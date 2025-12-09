#pragma once

#include <vector>
#include <climits>

namespace algs
{
    // 1.1.
    long long b_sequence (int n)
    {
        if (n == 1)
            return 2;
        if (n == 2)
            return 3;

        return b_sequence (n - 1) + b_sequence (n - 2);
    }
    // 1.2.
    int binary_sequences_no_two_ones (int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 2;

        std::vector<int> dp(n + 1);

        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }

    // 1.2. - version 2 (better)
    long long binary_sequences_no_two_ones_v2 (int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 2;

        long prev2 = 1;  // dp[i-2]
        long prev1 = 2;  // dp[i-1]

        for (int i = 2; i <= n; ++i)
        {
            long current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }

    // 2.
    int count_sequence (int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 2;
        if (n == 2)
            return 4;

        std::vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 4;

        for (int i = 3; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

        return dp[n];
    }

    // 3.
    int longest_increasing_subarray (const std::vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return 1;

        std::vector<int> dp(nums.size(), 1);
        int max_length = 1;

        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
                dp[i] = dp[i - 1] + 1;

            if (dp[i] > max_length)
                max_length = dp[i];
        }

        return max_length;
    }

    // 4.1.
    std::vector<std::vector<int>> pascal_triangle_recursive (int n)
    {
        std::vector<std::vector<int>> dp;

        for (int row = 0; row < n; ++row)
        {
            std::vector<int> current_row;

            for (int col = 0; col <= row; ++col)
            {
                if (col == 0 || col == row)
                    current_row.push_back (1);
                else
                    current_row.push_back (dp[row - 1][col - 1] + dp[row - 1][col]);
            }

            dp.push_back (current_row);
        }

        return dp;
    }

    // 4.2.
    std::vector<std::vector<int>> pascal_triangle_iterative (int n)
    {
        std::vector<std::vector<int>> dp;

        for (int i = 0; i < n; ++i)
        {
            std::vector<int> row(i + 1, 1);
            dp.push_back (row);
        }

        for (int row = 2; row < n; ++row)
            for (int col = 1; col < row; ++col)
                dp[row][col] = dp[row - 1][col - 1] + dp[row - 1][col];

        return dp;
    }

    // 5.
    int max_profit_stock (const std::vector<int>& prices)
    {
        if (prices.size() < 2)
            return 0;

        int profit = 0;
        int min_price = prices[0];

        for (size_t i = 1; i < prices.size(); i++)
        {
            profit = std::max (profit, prices[i] - min_price);
            min_price = std::min (min_price, prices[i]);
        }

        return profit;
    }

    // 6.1.
    int coin_change_recursive_helper (const std::vector<int>& coins,
                                      int amount,
                                      std::vector<int>& memo)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;

        if (memo[amount] != -2)
            return memo[amount];

        int min_coins = INT_MAX;

        for (int coin : coins)
        {
            int res = coin_change_recursive_helper (coins, amount - coin, memo);
            if (res >= 0 && res < min_coins)
                min_coins = res + 1;
        }

        memo[amount] = (min_coins == INT_MAX) ? -1 : min_coins;

        return memo[amount];
    }

    int coin_change_recursive (const std::vector<int>& coins, int amount)
    {
        std::vector<int> memo(amount + 1, -2);
        return coin_change_recursive_helper (coins, amount, memo);
    }

    // 6.2.
    int coin_change_iterative (const std::vector<int>& coins, int amount)
    {
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int coin : coins)
            {
                if (coin <= i)
                    dp[i] = std::min (dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }

}
