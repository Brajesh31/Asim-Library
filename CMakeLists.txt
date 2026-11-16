cmake_minimum_required(VERSION 3.16)
project(AsimLibrary VERSION 1.0.0 LANGUAGES CXX)

option(ASIM_LIBRARY_BUILD_DEMO "Build the console demonstration" ON)
option(ASIM_LIBRARY_BUILD_TESTS "Build the automated test executable" ON)

add_library(asim_library asim_library.cpp)
add_library(AsimLibrary::asim_library ALIAS asim_library)
target_include_directories(asim_library PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>)
target_compile_features(asim_library PUBLIC cxx_std_17)
set_target_properties(asim_library PROPERTIES
    CXX_EXTENSIONS OFF
    VERSION ${PROJECT_VERSION}
    SOVERSION 1)

if(MSVC)
    target_compile_options(asim_library PRIVATE /W4 /permissive-)
else()
    target_compile_options(asim_library PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(ASIM_LIBRARY_BUILD_DEMO)
    add_executable(asim_library_demo main.cpp)
    target_link_libraries(asim_library_demo PRIVATE AsimLibrary::asim_library)
endif()

if(ASIM_LIBRARY_BUILD_TESTS)
    enable_testing()
    add_executable(asim_library_tests tests/test_asim_library.cpp)
    target_link_libraries(asim_library_tests PRIVATE AsimLibrary::asim_library)
    add_test(NAME asim_library_tests COMMAND asim_library_tests)
endif()
