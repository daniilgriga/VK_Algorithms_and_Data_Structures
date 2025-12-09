#include <iostream>

#include "algorithms.hpp"

void test_task_1()
{
    std::vector<int> testCases = {0, 1, 2, 3, 4, 5, 10};

    for (int n : testCases)
    {
        int result = algs::binary_sequences_no_two_ones_v2 (n);
        std::cout << "[1]: N = " << n << " -> " << result << " sequences" << std::endl;
    }

    std::cout << std::endl;
}

void test_task_2()
{
    std::vector<int> testCases = {0, 1, 2, 3, 4, 5, 6, 10};

    for (int n : testCases)
    {
        int result = algs::count_sequence (n);
        std::cout << "[2]: N = " << n << " -> " << result << " sequences" << std::endl;
    }

    std::cout << std::endl;
}

void test_task_3()
{
    std::vector<std::vector<int>> testCases = {
        {3, 2, 8, 9, 5, 10},
        {1, 2, 7, 9, 0, 10},
        {8, 8, 8, 8},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1}
    };

    for (const auto& nums : testCases)
    {
        int result = algs::longest_increasing_subarray (nums);

        std::cout << "[3]: [";
        for (size_t i = 0; i < nums.size(); i++)
        {
            std::cout << nums[i];
            if (i < nums.size() - 1) std::cout << ", ";
        }
        std::cout << "] -> " << result << std::endl;
    }

    std::cout << std::endl;
}

void print_vector (const std::vector<int>& v)
{
    for (int val : v)
        std::cout << val << " ";
    std::cout << std::endl;
}

void test_task_4()
{
    int n = 7;

    std::cout << "[4.1]: Recursive version (n=" << n << "):" << std::endl;
    auto result1 = algs::pascal_triangle_recursive (n);

    for (const auto& row : result1)
        print_vector (row);

    std::cout << "\n[4.2]: Iterative version (n=" << n << "):" << std::endl;
    auto result2 = algs::pascal_triangle_iterative (n);

    for (const auto& row : result2)
        print_vector (row);

    std::cout << std::endl;
}

void test_task_5()
{
    std::vector<std::vector<int>> testCases = {
        {8, 9, 3, 7, 4, 16, 12},
        {1, 2, 3, 4, 5, 6, 7},
        {8, 7, 6, 5, 4, 3, 2},
        {7, 1, 5, 3, 6, 4}
    };

    for (const auto& prices : testCases)
    {
        int result = algs::max_profit_stock (prices);
        std::cout << "[5]: [";
        for (size_t i = 0; i < prices.size(); i++)
        {
            std::cout << prices[i];
            if (i < prices.size() - 1) std::cout << ", ";
        }
        std::cout << "] -> profit = " << result << std::endl;
    }

    std::cout << std::endl;
}

void test_task_6()
{
    std::vector<std::pair<std::vector<int>, int>> testCases = {
        {{1, 2, 5}, 11},
        {{2}, 3},
        {{1}, 0},
        {{1, 3, 4}, 6}
    };

    std::cout << "[6.1]: Recursive version:" << std::endl;
    for (const auto& [coins, amount] : testCases)
    {
        int result = algs::coin_change_recursive (coins, amount);
        std::cout << "[6.1]: coins=[";

        for (size_t i = 0; i < coins.size(); i++)
        {
            std::cout << coins[i];
            if (i < coins.size() - 1) std::cout << ", ";
        }
        std::cout << "], amount=" << amount << " -> " << result << std::endl;
    }

    std::cout << "\n[6.2] Iterative version:" << std::endl;
    for (const auto& [coins, amount] : testCases)
    {
        int result = algs::coin_change_iterative (coins, amount);

        std::cout << "[6.2]: coins=[";
        for (size_t i = 0; i < coins.size(); i++)
        {
            std::cout << coins[i];
            if (i < coins.size() - 1) std::cout << ", ";
        }
        std::cout << "], amount=" << amount << " -> " << result << std::endl;
    }

    std::cout << std::endl;
}

void test_task_7()
{
    std::vector<std::string> testCases = {
        "babad",
        "cbbd",
        "racecar",
        "a",
        "ac",
        "oajdbhuduu"
    };

    std::cout << "[7.1]:" << std::endl;
    for (const auto& s : testCases)
    {
        std::string result = algs::longest_palindrome_expand (s);
        std::cout << "\"" << s << "\" -> \"" << result << "\"" << std::endl;
    }

    std::cout << "\n[7.2]: DP version:" << std::endl;
    for (const auto& s : testCases)
    {
        std::string result = algs::longest_palindrome_dp (s);
        std::cout << "\"" << s << "\" -> \"" << result << "\"" << std::endl;
    }

    std::cout << std::endl;
}

int main()
{
    test_task_1();
    test_task_2();
    test_task_3();
    test_task_4();
    test_task_5();
    test_task_6();
    test_task_7();

    return 0;
}
