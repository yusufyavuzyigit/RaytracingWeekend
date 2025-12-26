cmake_minimum_required(VERSION 3.60)
project(ProjName LANGUAGES CXX)

option(ENABLE_TESTS "Build unit tests" OFF)
option(ENABLE_BENCHMARKS "Build benchmarks" OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(Cmake/CPM.cmake)
set(CPM_DOWNLOAD_ALL FALSE)

add_subdirectory(App)
add_subdirectory(Core)

if (ENABLE_TESTS)
    enable_testing()
    add_subdirectory(Tests)
endif()

if (ENABLE_BENCHMARKS)
    add_subdirectory(Benchmarks)
endif()

# May work, may not work. If works, nice.
if(MSVC)
    set_property(GLOBAL PROPERTY VS_STARTUP_PROJECT App)
endif()