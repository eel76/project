cmake_minimum_required (VERSION 3.11)

project (applications.core LANGUAGES CXX)
include (GenerateExportHeader)

add_library (applications.core SHARED)
generate_export_header(applications.core BASE_NAME applications_core)

target_sources (applications.core PRIVATE src/progressdialog.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/progressdialog.h)
target_sources (applications.core PRIVATE src/totext.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/totext.h)
target_sources (applications.core PRIVATE src/translation_context.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/translation_context.h)

target_include_directories(applications.core
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_compile_options(applications.core PRIVATE $<$<CXX_COMPILER_ID:MSVC>:-wd4251>)
target_compile_features(applications.core PUBLIC cxx_std_17)
target_link_libraries(applications.core PRIVATE algorithms.core)
