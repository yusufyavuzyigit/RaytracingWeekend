CPMAddPackage(
    NAME benchmark
    GITHUB_REPOSITORY google/benchmark
    VERSION 1.9.4
    OPTIONS
        "BENCHMARK_ENABLE_TESTING OFF"
        "BENCHMARK_ENABLE_INSTALL OFF"
)

add_executable(core_benchmarks 
    core_benchmark.cpp
)

target_link_libraries(core_benchmarks
    PRIVATE
        core_lib
        benchmark::benchmark
)