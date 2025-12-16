#include <iostream>
#include <vector>

#include "algorithms.hpp"

void test_task_1()
{
    std::vector<int> arr = {3, 8, 6, 9, 9, 8, 6, 11};
    int k = 3;

    std::cout << "[1]: Maximum subarray sum (k=" << k << "): "
              << algs::max_subarray_sum (arr, k) << std::endl;

    std::vector<int> arr2 = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k2 = 4;
    std::cout << "[1]: Maximum subarray sum (k=" << k2 << "): "
              << algs::max_subarray_sum (arr2, k2) << std::endl;

    std::cout << std::endl;
}

void test_task_2()
{
    std::vector<int> nums1 = {3, 8, 6, 9, 2, 1, 4};
    int k1 = 11;

    std::cout << "[2]: Subarray sum equals " << k1 << ": "
              << algs::subarray_sum (nums1, k1) << std::endl;

    std::vector<int> nums2 = {1, 1, 1};
    int k2 = 2;
    std::cout << "[2]: Subarray sum equals " << k2 << ": "
              << algs::subarray_sum (nums2, k2) << std::endl;

    std::vector<int> nums3 = {1, -1, 0};
    int k3 = 0;
    std::cout << "[2]: Subarray sum equals " << k3 << ": "
              << algs::subarray_sum (nums3, k3) << std::endl;

    std::cout << std::endl;
}

int main()
{
    test_task_1();
    test_task_2();

    return 0;
}
