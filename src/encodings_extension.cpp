#include "encodings_extension.hpp"
#include "duckdb.hpp"
#include "duckdb/common/exception.hpp"
#include "duckdb/common/string_util.hpp"
#include "duckdb/function/encoding_function.hpp"
#include "duckdb/function/table_function.hpp"
#include "duckdb/main/extension/extension_loader.hpp"

#include "generated_encoded_function.hpp"

#include <algorithm>

namespace duckdb {

//===--------------------------------------------------------------------===//
// duckdb_encodings(): lists every encoding name read_csv accepts
//===--------------------------------------------------------------------===//
struct EncodingInformation {
	string name;
	idx_t max_input_bytes;
	idx_t max_output_bytes;
	idx_t map_size;
};

struct DuckDBEncodingsData : public GlobalTableFunctionState {
	vector<EncodingInformation> entries;
	idx_t offset = 0;
};

// The type of the `names` parameter of a table function bind callback (vector<string> & up to DuckDB 1.5,
// vector<Identifier> & afterwards), so that this compiles against both.
template <class BIND>
struct BindNamesParameter;
template <class RETURN, class CONTEXT, class INPUT, class TYPES, class NAMES>
struct BindNamesParameter<RETURN (*)(CONTEXT, INPUT, TYPES, NAMES)> {
	using type = NAMES;
};
using bind_names_t = BindNamesParameter<table_function_bind_t>::type;

static unique_ptr<FunctionData> DuckDBEncodingsBind(ClientContext &context, TableFunctionBindInput &input,
                                                    vector<LogicalType> &return_types, bind_names_t names) {
	// The encoding name, as accepted by read_csv(encoding := ...)
	names.emplace_back("name");
	return_types.emplace_back(LogicalTypeId::VARCHAR);
	// The longest byte sequence that encodes a single character
	names.emplace_back("max_input_bytes");
	return_types.emplace_back(LogicalTypeId::BIGINT);
	// The longest UTF-8 output produced for one byte sequence of the encoding
	names.emplace_back("max_output_bytes");
	return_types.emplace_back(LogicalTypeId::BIGINT);
	// The number of byte sequences in the conversion table (0 for DuckDB's built-in decoders)
	names.emplace_back("map_size");
	return_types.emplace_back(LogicalTypeId::BIGINT);
	return nullptr;
}

static unique_ptr<GlobalTableFunctionState> DuckDBEncodingsInit(ClientContext &context, TableFunctionInitInput &input) {
	auto result = make_uniq<DuckDBEncodingsData>();
	auto &config = DBConfig::GetConfig(context);
	for (auto &function_ref : config.GetLoadedEncodedFunctions()) {
		auto &function = function_ref.get();
		result->entries.push_back(
		    {function.GetName(), function.GetLookupBytes(), function.GetBytesPerIteration(), function.map_size});
	}
	std::sort(result->entries.begin(), result->entries.end(),
	          [](const EncodingInformation &a, const EncodingInformation &b) { return a.name < b.name; });
	return std::move(result);
}

static void DuckDBEncodingsFunction(ClientContext &context, TableFunctionInput &data_p, DataChunk &output) {
	auto &data = data_p.global_state->Cast<DuckDBEncodingsData>();
	idx_t count = 0;
	while (data.offset < data.entries.size() && count < STANDARD_VECTOR_SIZE) {
		auto &entry = data.entries[data.offset++];
		output.data[0].SetValue(count, Value(entry.name));
		output.data[1].SetValue(count, Value::BIGINT(NumericCast<int64_t>(entry.max_input_bytes)));
		output.data[2].SetValue(count, Value::BIGINT(NumericCast<int64_t>(entry.max_output_bytes)));
		output.data[3].SetValue(count, Value::BIGINT(NumericCast<int64_t>(entry.map_size)));
		count++;
	}
	// DataChunk::SetCardinality is deprecated on DuckDB main, but its replacements do not exist on 1.5 yet
	output.SetCardinality(count);
}

static void LoadInternal(ExtensionLoader &loader) {
	auto &config = loader.GetDatabaseInstance().config;
	duckdb_encodings::RegisterEncodings(config);

	loader.RegisterFunction(
	    TableFunction("duckdb_encodings", {}, DuckDBEncodingsFunction, DuckDBEncodingsBind, DuckDBEncodingsInit));
}

void EncodingsExtension::Load(ExtensionLoader &loader) {
	LoadInternal(loader);
}
std::string EncodingsExtension::Name() {
	return "encodings";
}

std::string EncodingsExtension::Version() const {
#ifdef EXT_VERSION_ENCODINGS
	return EXT_VERSION_ENCODINGS;
#else
	return "";
#endif
}

} // namespace duckdb

extern "C" {

DUCKDB_CPP_EXTENSION_ENTRY(encodings, loader) {
	duckdb::LoadInternal(loader);
}
}
