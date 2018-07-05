cmake_minimum_required (VERSION 3.11)

project (algorithms.smoothing LANGUAGES CXX)
include (GenerateExportHeader)

add_library (algorithms.smoothing SHARED)
generate_export_header(algorithms.smoothing BASE_NAME algorithms_smoothing)

target_sources (algorithms.smoothing PRIVATE src/smoothing.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/smoothing.h)
target_sources (algorithms.smoothing PRIVATE src/smoothinginfo.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/smoothinginfo.h)

target_include_directories(algorithms.smoothing
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_compile_features(algorithms.smoothing PUBLIC cxx_std_17)

target_link_libraries(algorithms.smoothing PRIVATE core)
