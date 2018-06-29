cmake_minimum_required (VERSION 3.11)

project (core VERSION 1.0.0 LANGUAGES CXX)
include (GenerateExportHeader)

add_library (core SHARED)
generate_export_header(core)

target_sources (core PRIVATE src/report.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/report.h)
target_sources (core PRIVATE src/subscription.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/subscription.h)
target_sources (core PRIVATE src/subscriptions.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/subscriptions.h)

target_include_directories(core
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_compile_features(core PUBLIC cxx_std_17)

