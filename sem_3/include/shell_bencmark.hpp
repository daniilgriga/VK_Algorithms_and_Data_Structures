#pragma once

#include "algorithms.hpp"
#include <chrono>
#include <iomanip>
#include <fstream>
#include <functional>

namespace algs
{
    class Benchmark
    {
    public:
        enum class Data_t
        {
            RANDOM,
            SORTED,
            REVERSE,
            FEW_UNIQUE
        };

    private:
        struct BenchmarkResult
        {
            std::string algorithm_name_;
            Data_t data_type_;
            int data_size_;
            long long time_microsec_;
            bool sorted_;
        };

        std::vector<BenchmarkResult> results_;

        static void shell_sort_hibbard (std::vector<int>& v)
        {
            shell_sort (v, ShellSeq_t::HIBBARD);
        }

        static void shell_sort_pratt (std::vector<int>& v)
        {
            shell_sort (v, ShellSeq_t::PRATT);
        }

        static void shell_sort_ciura (std::vector<int>& v)
        {
            shell_sort (v, ShellSeq_t::CIURA);
        }

        std::string data_type_to_string (Data_t type) const
        {
            switch (type)
            {
                case Data_t::RANDOM: return "random";
                case Data_t::SORTED: return "sorted";
                case Data_t::REVERSE: return "reverse";
                case Data_t::FEW_UNIQUE: return "few_unique";

                default: return "unknown";
            }
        }

    public:
        Benchmark() = default;

        template<typename Func>
        BenchmarkResult run_single_benchmark (const std::string& name, Func algorithm,
                                              std::vector<int> test_data, Data_t data_type = Data_t::RANDOM)
        {
            std::vector<int> vec = test_data;

            auto start = std::chrono::high_resolution_clock::now();
            algorithm (vec);
            auto end = std::chrono::high_resolution_clock::now();

            bool is_sorted = std::is_sorted (vec.begin(), vec.end());

            ll_t time = std::chrono::duration_cast<std::chrono::microseconds> (end - start).count();

            BenchmarkResult result {name, data_type, static_cast<int>(test_data.size()), time, is_sorted};

            results_.push_back (result);

            return result;
        }

        template<typename Func>
        void run_algorithm_series (const std::string& algorithm_name, Func algorithm,
                                   const std::vector<int>& sizes, Data_t data_type)
        {
            std::string data_type_str = data_type_to_string (data_type);
            std::cout << "\n  " << algorithm_name << " - " << data_type_str << std::endl;
            std::cout << "Size\tTime (mcs)\tStatus" << std::endl;
            std::cout << "========================================" << std::endl;

            for (int size : sizes)
            {
                std::vector<int> test_data = generate_test_data (data_type, size);

                auto result = run_single_benchmark (algorithm_name, algorithm, test_data, data_type);

                std::cout << size << "\t" << result.time_microsec_ << "\t\t"
                          << (result.sorted_ ? "Sorted" : "Unsorted") << std::endl;
            }
        }

        void compare_shell_sorts (const std::vector<int>& sizes, Data_t data_type)
        {
            std::string data_type_str = data_type_to_string (data_type);
            std::cout << "\nCOMPARISON OF SHELL SORTS (" << data_type_str << ")" << std::endl;
            std::cout << "##########################################" << std::endl;

            std::vector<std::pair<std::string, std::function<void(std::vector<int>&)>>> algorithms = {
                {"Shell (Hibbard)", shell_sort_hibbard},
                {"Shell (Pratt)",   shell_sort_pratt},
                {"Shell (Ciura)",   shell_sort_ciura} };

            for (const auto& [name, algo] : algorithms)
            {
                std::cout << "\n" << name << ":" << std::endl;
                run_algorithm_series (name, algo, sizes, data_type);
            }
        }

        std::vector<int> generate_test_data (Data_t type, int size)
        {
            switch (type)
            {
                case Data_t::RANDOM: return generate_random_array (size);
                case Data_t::SORTED: return generate_sorted_array (size);
                case Data_t::REVERSE: return generate_reverse_sorted_array (size);
                case Data_t::FEW_UNIQUE: return generate_few_unique_array (size);

                default: return generate_random_array (size);
            }
        }

        std::vector<int> generate_random_array (int size) // the general case
        {
            return generate_rand_vector (size);
        }

        std::vector<int> generate_sorted_array (int size) // the best case
        {
            std::vector<int> vec (size);

            for (int i = 0; i < size; i++)
                vec[i] = i;

            return vec;
        }

        std::vector<int> generate_reverse_sorted_array (int size) // the worst case
        {
            std::vector<int> vec (size);

            for (int i = 0; i < size; i++)
                vec[i] = size - i;

            return vec;
        }

        std::vector<int> generate_few_unique_array (int size, int unique_count = 10) // lots of duplicates
        {
            std::vector<int> vec (size);
            std::random_device rd;
            std::mt19937 gen (rd());
            std::uniform_int_distribution<int> dis (1, unique_count);

            for (int i = 0; i < size; i++)
                vec[i] = dis(gen);

            return vec;
        }

        void print_summary ()
        {
            std::cout << "\nBENCHMARKING RESULTS" << std::endl;
            std::cout << "##########################################" << std::endl;

            std::unordered_map<std::string, std::vector<BenchmarkResult>> grouped_results;

            for (const auto& result : results_)
                grouped_results[result.algorithm_name_].push_back (result);

            for (const auto& [algo_name, algo_results] : grouped_results)
            {
                std::cout << "\n" << algo_name << ":" << std::endl;
                for (const auto& result : algo_results)
                {
                    std::cout << "  Size " << result.data_size_ << " ("
                              << data_type_to_string (result.data_type_) << "): "
                              << result.time_microsec_ << " mcs "
                              << (result.sorted_ ? "Sorted" : "Unsorted") << std::endl;
                }
            }
        }

        void export_to_csv (const std::string& filename = "shell_sort_benchmark.csv")
        {
            std::ofstream file (filename);
            file << "Algorithm,Data_t,Size,TimeMicroseconds,Correct\n";

            for (const auto& result : results_)
            {
                file << result.algorithm_name_ << ","
                     << data_type_to_string (result.data_type_) << ","
                     << result.data_size_ << ","
                     << result.time_microsec_ << ","
                     << (result.sorted_ ? "true" : "false") << "\n";
            }

            file.close();
            std::cout << "Results in " << filename << std::endl;
        }
    };
}
