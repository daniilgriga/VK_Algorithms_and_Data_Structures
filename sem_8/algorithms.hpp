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

} // namespace algs
