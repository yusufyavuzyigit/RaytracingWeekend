#include <benchmark/benchmark.h>
#include <core/core.h>

static void BM_Factorial(benchmark::State& state)
{
    const std::uint64_t n = static_cast<std::uint64_t>(state.range(0));

    for (auto _ : state)
    {
        auto result = Factorial(n);
        benchmark::DoNotOptimize(result);
    }
}

// Test multiple input sizes
BENCHMARK(BM_Factorial)
    ->Arg(5)
    ->Arg(10)
    ->Arg(15)
    ->Arg(20);

BENCHMARK_MAIN();