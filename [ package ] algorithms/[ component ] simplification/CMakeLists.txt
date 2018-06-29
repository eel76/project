cmake_minimum_required (VERSION 3.11)

project (simplification VERSION 1.0.0 LANGUAGES CXX)
include (GenerateExportHeader)

add_library (simplification SHARED)
generate_export_header(simplification)

target_sources (simplification PRIVATE src/simplification.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/simplification.h)
target_sources (simplification PRIVATE src/simplificationinfo.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/simplificationinfo.h)

target_include_directories(simplification
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_compile_features(simplification PUBLIC cxx_std_17)

target_link_libraries(simplification PRIVATE core)
