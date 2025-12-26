add_library(core_lib)

# CPM Package Example

# CPMAddPackage(
#   NAME          # The unique name of the dependency (should be the exported target's name)
#   VERSION       # The minimum version of the dependency (optional, defaults to 0)
#   PATCHES       # Patch files to be applied sequentially using patch and PATCH_OPTIONS (optional)
#   OPTIONS       # Configuration options passed to the dependency (optional)
#   DOWNLOAD_ONLY # If set, the project is downloaded, but not configured (optional)
#   [...]         # Origin parameters forwarded to FetchContent_Declare, see below
# )

# CPMAddPackage(
#     NAME spdlog
#     GITHUB_REPOSITORY gabime/spdlog
#     VERSION 1.13.0
    #  OPTIONS
    #     "SPDLOG_FMT_EXTERNAL ON"
# )

# target_link_libraries(core
#     PUBLIC spdlog::spdlog
# )

target_sources(core_lib
    PRIVATE
        src/core.cpp
)

target_include_directories(core_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/include/core
)

target_compile_features(core_lib PUBLIC cxx_std_17)
