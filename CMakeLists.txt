cmake_minimum_required(VERSION 3.5...3.29)

# Set extension name here
set(TARGET_NAME encodings)

project(${TARGET_NAME})

set(CMAKE_CXX_STANDARD "17" CACHE STRING "C++ standard to enforce")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# The extension is written against DuckDB's stable C++ API only: it includes nothing but duckdb_cpp.hpp (and
# duckdb_cpp_extension.hpp for its entrypoint) and ZSTD's header, and links the C++ API archive and ZSTD. It does not
# depend on the internals of the DuckDB it is loaded into.
set(EXTENSION_SOURCES src/encodings_extension.cpp
    src/generated_encoded_functions.cpp src/encodings_dataset.cpp)

build_loadable_extension_capi_unstable(${TARGET_NAME} "" ${EXTENSION_SOURCES})
target_compile_definitions(${TARGET_NAME}_loadable_extension
                           PRIVATE DUCKDB_CPP_API_LOADABLE)
target_include_directories(
  ${TARGET_NAME}_loadable_extension
  PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src/include
          ${DUCKDB_MODULE_BASE_DIR}/tools/cpp)
# The conversion tables are compressed with ZSTD, which is compiled into the extension
target_include_directories(
  ${TARGET_NAME}_loadable_extension
  PRIVATE ${DUCKDB_MODULE_BASE_DIR}/third_party/zstd/include)
target_link_libraries(${TARGET_NAME}_loadable_extension duckdb_cpp_api_loadable
                      duckdb_zstd)
