cmake_minimum_required (VERSION 3.11)

project (gui.totext LANGUAGES CXX)
include (GenerateExportHeader)

add_library (gui.totext SHARED)
generate_export_header(gui.totext BASE_NAME gui_totext)

target_sources (gui.totext PRIVATE src/totext.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/totext.h)
target_sources (gui.totext PRIVATE src/translationcontext.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/translationcontext.h)

target_include_directories(gui.totext
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_compile_options(gui.totext PRIVATE $<$<CXX_COMPILER_ID:MSVC>:-wd4251>)
target_compile_features(gui.totext PUBLIC cxx_std_17)
target_link_libraries(gui.totext PUBLIC service.core)
