cmake_minimum_required(VERSION 3.5)

# Set extension name here
set(TARGET_NAME encodings)

set(EXTENSION_NAME ${TARGET_NAME}_extension)
set(LOADABLE_EXTENSION_NAME ${TARGET_NAME}_loadable_extension)

project(${TARGET_NAME})
include_directories(src/include)

set(EXTENSION_SOURCES src/encodings_extension.cpp
    src/generated_encoded_functions.cpp src/encodings_dataset.cpp)

build_static_extension(${TARGET_NAME} ${EXTENSION_SOURCES} ${ALL_OBJECT_FILES})
build_loadable_extension(${TARGET_NAME} "${ALL_OBJECT_FILES}"
                         ${EXTENSION_SOURCES})

# The conversion tables are compressed with ZSTD
target_include_directories(${EXTENSION_NAME}
                           PRIVATE ${CMAKE_SOURCE_DIR}/third_party/zstd/include)
target_include_directories(${LOADABLE_EXTENSION_NAME}
                           PRIVATE ${CMAKE_SOURCE_DIR}/third_party/zstd/include)
target_link_libraries(${EXTENSION_NAME} duckdb_zstd)
target_link_libraries(${LOADABLE_EXTENSION_NAME} duckdb_zstd)

set_property(TARGET ${EXTENSION_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${EXTENSION_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${LOADABLE_EXTENSION_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${LOADABLE_EXTENSION_NAME} PROPERTY CXX_STANDARD_REQUIRED
                                                        ON)

if (MSVC)
  target_compile_options(${EXTENSION_NAME} PRIVATE /bigobj)
  target_compile_options(${LOADABLE_EXTENSION_NAME} PRIVATE /bigobj)
endif()

install(
  TARGETS ${EXTENSION_NAME}
  EXPORT "${DUCKDB_EXPORT_SET}"
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}"
  ARCHIVE DESTINATION "${INSTALL_LIB_DIR}")
