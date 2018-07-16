cmake_minimum_required (VERSION 3.11)

project (algorithm.callback LANGUAGES CXX)
include (GenerateExportHeader)

add_library (algorithm.callback SHARED)
generate_export_header(algorithm.callback BASE_NAME algorithm_callback)

target_sources (algorithm.callback PRIVATE src/callback.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/callback.h)

target_include_directories(algorithm.callback
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_compile_options(algorithm.callback PRIVATE $<$<CXX_COMPILER_ID:MSVC>:-wd4251>)
target_compile_features(algorithm.callback PUBLIC cxx_std_17)
target_link_libraries(algorithm.callback PUBLIC service.core)
