#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

namespace algs
{
    // 1.
    int max_subarray_sum (const std::vector<int>& arr, int k)
    {
        int n = arr.size();

        if (n < k)
            return -1;

        int current_sum = 0;
        for (int i = 0; i < k; i++)
            current_sum += arr[i];

        int max_sum = current_sum;

        for (int i = k; i < n; i++)
        {
            current_sum = current_sum - arr[i - k] + arr[i];
            max_sum = std::max (max_sum, current_sum);
        }

        return max_sum;
    }

    // 2.
    int subarray_sum (const std::vector<int>& nums, int k)
    {
        int prefix_sum = 0;
        int count = 0;

        std::unordered_map<int, int> prefix_count;
        prefix_count[0] = 1;

        for (int num : nums)
        {
            prefix_sum += num;

            int target = prefix_sum - k;
            if (prefix_count.find (target) != prefix_count.end())
                count += prefix_count[target];

            prefix_count[prefix_sum]++;
        }

        return count;
    }

    // 3.
    int find_max_length (const std::vector<int>& nums)
    {
        int prefix_sum = 0;
        int max_len = 0;

        std::unordered_map<int, int> index_map;
        index_map[0] = -1;
        for (int i = 0; i < static_cast<int>(nums.size()); i++)
        {
            prefix_sum += (nums[i] == 0) ? -1 : 1;

            if (index_map.find (prefix_sum) != index_map.end())
            {
                int length = i - index_map[prefix_sum];
                max_len = std::max (max_len, length);
            }
            else
            {
                index_map[prefix_sum] = i;
            }
        }

        return max_len;
    }

    // 4.
    int pivot_index (const std::vector<int>& nums)
    {
        int total_sum = 0;
        int left_sum = 0;

        for (int num : nums)
            total_sum += num;

        for (int i = 0; i < nums.size(); i++)
        {
            if (left_sum == total_sum - left_sum - nums[i])
                return i;

            left_sum += nums[i];
        }

        return -1;
    }

} // namespace algs
