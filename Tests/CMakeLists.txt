# CPMAddPackage(
#     NAME Catch2
#     GITHUB_REPOSITORY catchorg/Catch2
#     VERSION 3.11.0
# )

CPMAddPackage("gh:catchorg/Catch2@3.11.0")

add_executable(core_tests
    tests.cpp
)

target_link_libraries(core_tests
    PRIVATE
        core_lib
        Catch2::Catch2WithMain
)

include(CTest)
include(${Catch2_SOURCE_DIR}/extras/Catch.cmake)
catch_discover_tests(core_tests)