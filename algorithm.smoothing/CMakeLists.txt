cmake_minimum_required (VERSION 3.11)

project (algorithm.smoothing LANGUAGES CXX)
include (GenerateExportHeader)

add_library (algorithm.smoothing SHARED)
generate_export_header(algorithm.smoothing BASE_NAME algorithm_smoothing)

target_sources (algorithm.smoothing PRIVATE src/smoothing.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/smoothing.h)
target_sources (algorithm.smoothing PRIVATE src/smoothingstatus.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/smoothingstatus.h)

target_include_directories(algorithm.smoothing
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_compile_options(algorithm.smoothing PRIVATE $<$<CXX_COMPILER_ID:MSVC>:-wd4251>)
target_compile_features(algorithm.smoothing PUBLIC cxx_std_17)
target_link_libraries(algorithm.smoothing PRIVATE algorithm.callback)
