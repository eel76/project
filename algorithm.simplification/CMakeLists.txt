cmake_minimum_required (VERSION 3.11)

project (algorithm.simplification LANGUAGES CXX)
include (GenerateExportHeader)

add_library (algorithm.simplification SHARED)
generate_export_header(algorithm.simplification BASE_NAME algorithm_simplification)

target_sources (algorithm.simplification PRIVATE src/simplification.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/simplification.h)
target_sources (algorithm.simplification PRIVATE src/simplificationstatus.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/simplificationstatus.h)

target_include_directories(algorithm.simplification
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_compile_options(algorithm.simplification PRIVATE $<$<CXX_COMPILER_ID:MSVC>:-wd4251>)
target_compile_features(algorithm.simplification PUBLIC cxx_std_17)
target_link_libraries(algorithm.simplification PRIVATE algorithm.callback)
