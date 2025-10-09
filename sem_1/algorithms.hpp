#pragma once

#include <iostream>
#include <vector>

using VecInt = std::vector<int>;

// 1.
struct TwoSum_t
{
    int a;
    int b;
};

static TwoSum_t two_sum (VecInt& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    int sum = 0;
    while (left < right)
    {
        sum = nums[left] + nums[right];

        if (sum == target)
            return {nums[left], nums[right]};
        else if (sum < target)
            left++;
        else
            right--;
    }

    return {};
}

// 2.
static void reverse_array (VecInt& arr)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        std::swap (arr[left], arr[right]);
        left++;
        right--;
    }
}

// 3.
static void reverse_array (VecInt& nums, int left, int right)
{
    while (left < right)
    {
        std::swap (nums[left], nums[right]);
        left++;
        right--;
    }
}

static void reverse_a_part_of_array (VecInt& nums, int k)
{
    size_t n = nums.size();

    reverse_array (nums, 0, n - 1);
    reverse_array (nums, 0, (k % n) - 1);
    reverse_array (nums, (k % n), n - 1);
}

// 4.
static VecInt merge_sorted_arrays (VecInt& arr1, VecInt& arr2)
{
    VecInt merged_arr;

    size_t ptr1 = 0;
    size_t ptr2 = 0;

    while (ptr1 < arr1.size() && ptr2 < arr2.size())
    {
        if (arr1[ptr1] < arr2[ptr2])
            merged_arr.push_back (arr1[ptr1++]);
        else
            merged_arr.push_back (arr2[ptr2++]);
    }

    while (ptr1 < arr1.size())
        merged_arr.push_back (arr1[ptr1++]);

    while (ptr2 < arr2.size())
        merged_arr.push_back (arr2[ptr2++]);

    return merged_arr;
}

// 5.
static void merge (VecInt& nums1, int m, VecInt& nums2, int n)
{
    int ptr1 = m - 1;
    int ptr2 = n - 1;
    int ptr3 = n + m - 1;

    while (ptr2 >= 0)
    {
        if (ptr1 >= 0 && nums1[ptr1] > nums2[ptr2])
        {
            nums1[ptr3] = nums1[ptr1];
            ptr1--;
        }
        else
        {
            nums1[ptr3] = nums2[ptr2];
            ptr2--;
        }

        ptr3--;
    }
}

// 6.
static void sort_binary_array (VecInt& arr)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        if (arr[left] == 1)
        {
            std::swap (arr[left], arr[right]);
            right--;
        }
        else
        {
            left++;
        }
    }
}

// 7.
static void sort_colors (VecInt& nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high)
    {
        switch (nums[mid])
        {
            case 0:
                std::swap (nums[mid], nums[low]);
                mid++;
                low++;
                break;

            case 1:
                mid++;
                break;

            case 2:
                std::swap (nums[mid], nums[high]);
                high--;
                break;
        }
    }
}

// 8.
static void even_first (VecInt& arr)
{
    size_t even_index = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 0)
        {
            std::swap (arr[i], arr[even_index]);
            even_index++;
        }
    }
}

// 9.
static void zero_to_the_end (VecInt& arr)
{
    size_t ptr = 0;
    for (size_t i = 0; i < arr.size(); i++)
        if (arr[i] != 0)
            std::swap (arr[i], arr[ptr++]);
}
