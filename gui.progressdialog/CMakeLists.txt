cmake_minimum_required (VERSION 3.11)

project (gui.progressdialog LANGUAGES CXX)
include (GenerateExportHeader)

add_library (gui.progressdialog SHARED)
generate_export_header(gui.progressdialog BASE_NAME gui_progressdialog)

target_sources (gui.progressdialog PRIVATE src/progressdialog.cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/progressdialog.h)

target_include_directories(gui.progressdialog
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_compile_options(gui.progressdialog PRIVATE $<$<CXX_COMPILER_ID:MSVC>:-wd4251>)
target_compile_features(gui.progressdialog PUBLIC cxx_std_17)
target_link_libraries(gui.progressdialog PRIVATE algorithm.callback gui.totext)
