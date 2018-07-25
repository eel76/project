cmake_minimum_required (VERSION 3.11)

project (algorithm.core LANGUAGES CXX)
include (GenerateExportHeader)

add_library (algorithm.core SHARED)
generate_export_header(algorithm.core BASE_NAME algorithm_core)

target_sources (algorithm.core PRIVATE src/algorithm.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithm.h)

target_include_directories(algorithm.core
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_compile_options(algorithm.core PRIVATE $<$<CXX_COMPILER_ID:MSVC>:-wd4251>)
target_compile_features(algorithm.core PUBLIC cxx_std_17)
