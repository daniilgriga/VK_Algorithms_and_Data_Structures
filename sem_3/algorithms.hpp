#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

namespace algs
{
    using ll_t = long long;

    size_t sqrt_binary (size_t target)
    {
        int left = 0;
        int right = target / 2;

        while (left <= right)
        {
            int mid =  left + (right - left) / 2;

            if (mid*mid > target)
            {
                right = mid - 1;
                continue;
            }

            if (mid*mid < target)
            {
                left = mid + 1;
                continue;
            }

            return mid;
        }

        return right;
    }

    // 2.
    ll_t eval_mid (ll_t left, ll_t right) { return left + (right - left) / 2; }

    ll_t copy_time_binary (ll_t n, ll_t x, ll_t y)
    {
        if (n == 1)
            return std::min (x, y);

        ll_t left = 0;
        ll_t right = (n - 1) * std::max (x, y);

        while (left + 1 < right)
        {
            ll_t mid = eval_mid (left, right);

            ll_t copies = mid / x + mid / y;

            if (copies < n - 1)
                left = mid;
            else
                right = mid;
        }

        return right + std::min (x, y);
    }

    ll_t eval_gcd (ll_t a, ll_t b)
    {
        while (b != 0)
        {
            ll_t temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    ll_t eval_lcm (ll_t a, ll_t b)
    {
        return a / eval_gcd (a, b) * b;
    }

    // Renat's method, i guess?
    ll_t copy_time_analytic (ll_t n, ll_t x, ll_t y)
    {
        if (n == 1)
            return std::min (x, y);

        ll_t good_time = eval_lcm (x, y);
        ll_t ccl_copies = good_time / x + good_time / y;

        ll_t full_cycles = (n - 1) / ccl_copies;
        ll_t remaining_copies = (n - 1) % ccl_copies;

        ll_t time_for_full_cycles = full_cycles * good_time;

        ll_t time_for_remaining = 0;
        ll_t time_x = 0, time_y = 0;
        ll_t copies_exist = 0;

        while (copies_exist < remaining_copies)
        {
            if (time_x + x <= time_y + y)
            {
                time_x += x;
                time_for_remaining = std::max (time_for_remaining, time_x);
            }
            else
            {
                time_y += y;
                time_for_remaining = std::max (time_for_remaining, time_y);
            }

            copies_exist++;
        }

        return time_for_full_cycles + time_for_remaining + std::min (x, y);
    }

    // 3.
    int feed_animals_sort (std::vector<int>& animals, std::vector<int>& food)
    {
        if (animals.empty() || food.empty())
            return 0;

        std::sort (animals.begin(), animals.end());
        std::sort (food.begin(), food.end());

        size_t fed_count = 0;
        size_t food_index = 0;

        for (int need_animal : animals)
        {
            while (food_index < food.size() && food[food_index] < need_animal)
                food_index++;

            if (food_index < food.size())
            {
                fed_count++;
                food_index++;
            }
            else
            {
                break;
            }
        }

        return fed_count;
    }

    // 4.
    char find_extra_letter (const std::string& a, const std::string& b)
    {
        std::unordered_map<char, int> frq;

        for (char c : a)
            frq[c]++;

        for (char c : b)
        {
            if (frq.find(c) != frq.end())
            {
                frq[c]--;

                if (frq[c] == 0)
                    frq.erase (c);
            }
            else
            {
                return c;
            }
        }

        return ' ';
    }

    // 5.
    std::vector<int> two_sum (const std::vector<int>& data, int target)
    {
        std::unordered_map<int, int> cache;

        for (int i = 0; static_cast<size_t>(i) < data.size(); i++)
            cache[data[i]] = i;

        for (int i = 0; static_cast<size_t>(i) < data.size(); i++)
        {
            int diff = target - data[i];

            if (cache.find (diff) != cache.end() && cache[diff] != i)
                return {i, cache[diff]};            // indexes (from seminar)
                // return {diff, data[i]};          // values
        }

        return {};
    }
}
