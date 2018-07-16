cmake_minimum_required (VERSION 3.11)

project (service.core LANGUAGES CXX)
include (GenerateExportHeader)

add_library (service.core SHARED)
generate_export_header(service.core BASE_NAME service_core)

target_sources (service.core PRIVATE src/cancellation.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/cancellation.h)
target_sources (service.core PRIVATE src/subscription.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/subscription.h)
target_sources (service.core PRIVATE src/subscriptions.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/subscriptions.h)

target_include_directories(service.core
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_compile_options(service.core PRIVATE $<$<CXX_COMPILER_ID:MSVC>:-wd4251>)
target_compile_features(service.core PUBLIC cxx_std_17)
