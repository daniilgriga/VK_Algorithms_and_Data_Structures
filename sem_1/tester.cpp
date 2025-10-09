#include "algorithms.hpp"

static void print_vector (const std::vector<int>& vec)
{
    for (const auto& element : vec)
        std::cout << element << " ";

    std::cout << std::endl;
}

int main ()
{
    // 1.
    std::cout << "[1]: ";
    VecInt seq = {3, 8, 9, 11, 16, 18, 19, 21};
    TwoSum_t numbers = two_sum (seq, 40);
    std::cout << "a = " << numbers.a << " | b = " << numbers.b << std::endl;

    // 2.
    std::cout << "[2]: ";
    reverse_array (seq);
    print_vector (seq);

    // 3.
    std::cout << "[3]: ";
    reverse_a_part_of_array (seq, 3);
    print_vector (seq);

    // 4.
    std::cout << "[4]: ";
    VecInt arr1 = {3, 8, 10, 11};
    VecInt arr2 = {1, 7,  9, 12};
    VecInt merged_arr = merge_sorted_arrays (arr1, arr2);
    print_vector (merged_arr);

    // 5.
    std::cout << "[5]: ";
    arr1 = {3, 8, 10, 11, 0, 0, 0};
    arr2 = {1, 7, 9};
    merge (arr1, 4, arr2, 3);
    print_vector (arr1);

    // 6.
    std::cout << "[6]: ";
    VecInt bin_arr = {0, 1, 1, 0, 1, 0, 1, 0};
    sort_binary_array (bin_arr);
    print_vector (bin_arr);

    // 7.
    std::cout << "[7]: ";
    VecInt netherland_arr = {1, 0, 2, 1, 2, 0, 2 , 0, 1, 1};
    sort_colors (netherland_arr);
    print_vector (netherland_arr);

    // 8.
    std::cout << "[8]: ";
    VecInt arr_with_even = {7, 3, 2, 4, 1, 11, 8, 9};
    even_first (arr_with_even);
    print_vector (arr_with_even);

    // 9.
    std::cout << "[9]:" << std::endl;
    VecInt test1_arr = {0, 0, 1, 0, 3, 12};
    VecInt test2_arr = {0, 33, 57, 88, 60, 0, 0, 80, 99};
    VecInt test3_arr = {0, 0, 0, 18, 16, 0, 0, 77, 99};
    zero_to_the_end (test1_arr);
    std::cout << "  [9.1]: ";
    print_vector (test1_arr);
    zero_to_the_end (test2_arr);
    std::cout << "  [9.2]: ";
    print_vector (test2_arr);
    zero_to_the_end (test3_arr);
    std::cout << "  [9.3]: ";
    print_vector (test3_arr);

    return 0;
}
