cmake_minimum_required (VERSION 3.11)

project (algorithms.simplification LANGUAGES CXX)
include (GenerateExportHeader)

add_library (algorithms.simplification SHARED)
generate_export_header(algorithms.simplification BASE_NAME algorithms_simplification)

target_sources (algorithms.simplification PRIVATE src/simplification.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/simplification.h)
target_sources (algorithms.simplification PRIVATE src/simplificationinfo.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/simplificationinfo.h)

target_include_directories(algorithms.simplification
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_compile_features(algorithms.simplification PUBLIC cxx_std_17)

target_link_libraries(algorithms.simplification PRIVATE core)
