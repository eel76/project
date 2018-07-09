cmake_minimum_required (VERSION 3.11)

project (algorithms.core LANGUAGES CXX)
include (GenerateExportHeader)

add_library (algorithms.core SHARED)
generate_export_header(algorithms.core BASE_NAME algorithms_core)

target_sources (algorithms.core PRIVATE src/callback.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/callback.h)
target_sources (algorithms.core PRIVATE src/subscription.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/subscription.h)
target_sources (algorithms.core PRIVATE src/subscriptions.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/subscriptions.h)

target_include_directories(algorithms.core
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_compile_options(algorithms.core PRIVATE $<$<CXX_COMPILER_ID:MSVC>:-wd4251>)
target_compile_features(algorithms.core PUBLIC cxx_std_17)
