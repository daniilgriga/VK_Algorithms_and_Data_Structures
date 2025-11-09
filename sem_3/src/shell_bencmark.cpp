#include "shell_bencmark.hpp"

int main ()
{
    algs::Benchmark benchmark;

    std::vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    std::vector<algs::Benchmark::Data_t> data_types =
    {
        algs::Benchmark::Data_t::RANDOM,
        algs::Benchmark::Data_t::SORTED,
        algs::Benchmark::Data_t::REVERSE,
        algs::Benchmark::Data_t::FEW_UNIQUE
    };

    for (const auto& data_type : data_types)
        benchmark.compare_shell_sorts (sizes, data_type);

    benchmark.print_summary();
    benchmark.export_to_csv();

    return 0;
}
