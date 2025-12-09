#include <iostream>

#include "algorithms.hpp"

void test_task_1()
{
    std::vector<int> testCases = {0, 1, 2, 3, 4, 5, 10};

    for (int n : testCases)
    {
        int result = algs::binary_sequences_no_two_ones_v2 (n);
        std::cout << "[1]: N = " << n << " → " << result << " sequences" << std::endl;
    }

    std::cout << std::endl;
}

void test_task_2()
{
    std::vector<int> testCases = {0, 1, 2, 3, 4, 5, 6, 10};

    for (int n : testCases)
    {
        int result = algs::count_sequence (n);
        std::cout << "[2]: N = " << n << " → " << result << " sequences" << std::endl;
    }

    std::cout << std::endl;
}


int main()
{
    test_task_1();
    test_task_2();

    return 0;
}
