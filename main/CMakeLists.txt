cmake_minimum_required (VERSION 3.11)

project (main LANGUAGES CXX)

add_executable (main)

target_sources (main PRIVATE src/main.cpp src/eventloop.h src/store.h)

target_include_directories(main
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_compile_features(main PUBLIC cxx_std_17)
