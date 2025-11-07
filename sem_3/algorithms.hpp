#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <random>

namespace algs
{
    static void print_vector (const std::vector<int>& vec)
    {
        for (const auto& element : vec)
            std::cout << element << " ";

        std::cout << std::endl;
    }

    // 1.
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

    // 6.1. SHELL SORT
    enum class ShellSeq_t
    {
        HIBBARD,
        PRATT,
        CIURA
    };

    std::vector<int> generate_rand_vector (int size, int min = 1, int max = 1000)
    {
        std::vector<int> vec(size);
        std::random_device rd;
        std::mt19937 gen (rd());
        std::uniform_int_distribution<int> distr (min, max);

        for (int i = 0; i < size; i++)
            vec[i] = distr (gen);

        return vec;
    }

    // Hibbard: gap = 2^k - 1
    std::vector<int> generate_hibbard_seq (int n)
    {
        std::vector<int> gaps = {};
        int k = 1;

        while (true)
        {
            int gap = (1 << k) - 1;
            if (gap > n)
                break;

            gaps.push_back (gap);
            k++;
        }

        std::sort (gaps.rbegin(), gaps.rend());

        return gaps;
    }


    // Pratt: 2^i * 3^j
    std::vector<int> generate_pratt_seq (int n)
    {
        std::vector<int> gaps = {};

        for (int i = 0; ; i++)
        {
            int pow_2 = 1 << i;

            if (pow_2 > n)
                break;

            for (int j = 0; ; j++)
            {
                int gap = pow_2;

                for (int k = 0; k < j; k++)
                {
                    gap *= 3;
                    if (gap > n)
                        break;
                }

                if (gap > n)
                    break;

                gaps.push_back (gap);
            }
        }

        std::sort (gaps.begin(), gaps.end());   // for std::unique
        gaps.erase (std::unique (gaps.begin(), gaps.end()), gaps.end());
        std::sort (gaps.rbegin(), gaps.rend());

        return gaps;
    }

    // Ciura: ..., 701, 301, 132, 57, 23, 10, 4, 1
    std::vector<int> generate_ciura_seq (int n)
    {
        std::vector<int> base_gaps = {701, 301, 132, 57, 23, 10, 4, 1};
        std::vector<int> gaps = {};

        if (n <= 701)
        {
            for (int gap : base_gaps)
                if (gap <= n)
                    gaps.push_back (gap);
        }
        else
        {
            // extending the sequence for large arrays (from https://en.wikipedia.org/wiki/Shellsort)
            gaps = base_gaps;
            int next_gap = 701;

            while (next_gap * 2.25 < n)
            {
                next_gap = static_cast<int> (next_gap * 2.25);
                gaps.insert (gaps.begin(), next_gap);
            }
        }

        return gaps;
    }

    void shell_sort (std::vector<int>& vec, ShellSeq_t sequence_type)
    {
        int n = vec.size();
        std::vector<int> gaps = {};

        switch (sequence_type)
        {
            case ShellSeq_t::HIBBARD:
                gaps = generate_hibbard_seq (n);
                std::cout << "[6.1 (hibbard)]: generated seq -> ";
                break;

            case ShellSeq_t::PRATT:
                gaps = generate_pratt_seq (n);
                std::cout << "[6.1 (pratt)]: generated seq -> ";
                break;

            case ShellSeq_t::CIURA:
                gaps = generate_ciura_seq (n);
                std::cout << "[6.1 (ciura)]: generated seq -> ";
                break;
        }

        print_vector (gaps);

        for (int gap : gaps)
        {
            for (int i = gap; i < n; i++)
            {
                int temp = vec[i];
                int curr = i;

                while (curr >= gap && vec[curr - gap] > temp)
                {
                    vec[curr] = vec[curr - gap];
                    curr -= gap;
                }

                vec[curr] = temp;
            }
        }
    }

    // 6.2. (task)
    using StringVector = std::vector<std::string>;
    using AnagramResult = std::vector<StringVector>;

    AnagramResult group_anagrams (StringVector& strs)
    {
        std::unordered_map<std::string, StringVector> groups;

        for (const std::string& str : strs)
        {
            std::string key = str;
            std::sort (key.begin(), key.end());

            groups[key].push_back (str);
        }

        AnagramResult result = {};
        for (const auto& pair : groups)
            result.push_back (pair.second);

        return result;
    }

    void print_result (const AnagramResult& result)
    {
        std::cout << "[";

        for (size_t i = 0; i < result.size(); i++)
        {
            std::cout << "[";
            for (size_t j = 0; j < result[i].size(); j++)
            {
                std::cout << "\"" << result[i][j] << "\"";

                if (j < result[i].size() - 1)
                    std::cout << ", ";
            }

            std::cout << "]";
            if (i < result.size() - 1)
                std::cout << ", ";
        }

        std::cout << "]" << std::endl;
    }
}
