#include "duckdb_cpp_extension.hpp"

#include "encoding_registrar.hpp"
#include "encoding_registration.hpp"
#include "generated/registration.hpp"

#include <algorithm>
#include <mutex>
#include <string>
#include <vector>

namespace duckdb {
namespace duckdb_encodings {

//===--------------------------------------------------------------------===//
// duckdb_encodings(): lists every encoding name read_csv accepts
//===--------------------------------------------------------------------===//
struct EncodingsBindData {
	std::vector<RegisteredEncoding> entries;
};

struct EncodingsGlobalState {
	std::mutex lock;
	cxx::idx_t offset = 0;
};

static void DuckDBEncodingsBind(cxx::TableFunction::BindInput &input) {
	auto &factory = input.GetContext().GetFactory();
	// The encoding name, as accepted by read_csv(encoding := ...)
	input.AddResultColumn("name", factory.ParseType("VARCHAR"));
	// The longest byte sequence that encodes a single character
	input.AddResultColumn("max_input_bytes", factory.ParseType("BIGINT"));
	// The longest UTF-8 output produced for one byte sequence of the encoding
	input.AddResultColumn("max_output_bytes", factory.ParseType("BIGINT"));
	// The number of byte sequences in the conversion table (0 for DuckDB's built-in decoders)
	input.AddResultColumn("map_size", factory.ParseType("BIGINT"));

	EncodingsBindData bind_data;
	bind_data.entries = GetRegisteredEncodings();
	// The encodings DuckDB provides itself, which have no conversion table
	bind_data.entries.push_back({"utf-8", 1, 1, 0});
	bind_data.entries.push_back({"latin-1", 1, 2, 0});
	bind_data.entries.push_back({"utf-16", 4, 3, 0});
	std::sort(bind_data.entries.begin(), bind_data.entries.end(),
	          [](const RegisteredEncoding &a, const RegisteredEncoding &b) { return a.name < b.name; });
	input.SetBindData<EncodingsBindData>(std::move(bind_data));
}

static void DuckDBEncodingsInitGlobal(cxx::TableFunction::InitGlobalInput &input) {
	input.SetGlobalState<EncodingsGlobalState>();
}

static void DuckDBEncodingsExec(cxx::TableFunction::ExecInput &input) {
	const auto &bind_data = input.GetBindData<EncodingsBindData>();
	auto &state = input.GetGlobalState<EncodingsGlobalState>();
	auto chunk = input.GetOutputChunk();
	auto name = chunk.GetVector(0);
	auto max_input_bytes = chunk.GetVector(1).GetDataMutable<int64_t>();
	auto max_output_bytes = chunk.GetVector(2).GetDataMutable<int64_t>();
	auto map_size = chunk.GetVector(3).GetDataMutable<int64_t>();

	std::lock_guard<std::mutex> guard(state.lock);
	cxx::idx_t count = 0;
	while (state.offset < bind_data.entries.size() && count < chunk.GetCapacity()) {
		auto &entry = bind_data.entries[state.offset++];
		name.AssignString(count, entry.name);
		max_input_bytes[count] = static_cast<int64_t>(entry.max_input_bytes);
		max_output_bytes[count] = static_cast<int64_t>(entry.max_output_bytes);
		map_size[count] = static_cast<int64_t>(entry.map_size);
		count++;
	}
	name.SetSize(count);
}

} // namespace duckdb_encodings
} // namespace duckdb

DUCKDB_CPP_EXTENSION_ENTRYPOINT(duckdb::cxx::Extension &extension, duckdb::cxx::Context &context) {
	duckdb::duckdb_encodings::EncodingRegistrar registrar {extension, context.GetFactory()};
	duckdb::duckdb_encodings::RegistrationEncodedFunctions::RegisterFunctions(registrar);

	auto function = duckdb::cxx::TableFunction::Create(context.GetFactory());
	function.SetName("duckdb_encodings");
	function.SetBindCallback(duckdb::duckdb_encodings::DuckDBEncodingsBind)
	    .SetInitGlobalCallback(duckdb::duckdb_encodings::DuckDBEncodingsInitGlobal)
	    .SetExecCallback(duckdb::duckdb_encodings::DuckDBEncodingsExec);
	extension.Register(function);
}
