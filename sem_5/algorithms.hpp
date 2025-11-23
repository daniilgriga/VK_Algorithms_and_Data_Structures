#pragma once

#include <vector>
#include <queue>

namespace algs
{
    // 1.1.
    template<typename T>
    bool is_max_heap (const std::vector<T>& vec)
    {
        size_t n = vec.size();

        for (size_t i = 0; i <= (n - 2) / 2; i++)
        {
            size_t left = 2 * i + 1;
            size_t right = 2 * i + 2;

            if (left < n && vec[i] < vec[left])
                return false;

            if (right < n && vec[i] < vec[right])
                return false;
        }

        return true;
    }

    // 1.2.
    template<typename T>
    bool is_max_heap_by_bfs (const std::vector<T>& vec)
    {
        size_t n = vec.size();
        if (n <= 1)
            return true;

        std::queue<size_t> q;
        q.push(0);

        while (!q.empty())
        {
            size_t i = q.front();
            q.pop();

            size_t left  = 2 * i + 1;
            size_t right = 2 * i + 2;

            if (left < n)
            {
                if (vec[i] < vec[left])
                    return false;

                q.push (left);
            }

            if (right < n)
            {
                if (vec[i] < vec[right])
                    return false;

                q.push (right);
            }
        }

        return true;
    }

    // 1.3.
    template<typename T>
    bool is_max_heap_complete (const std::vector<T>& arr)
    {
        size_t n = arr.size();
        if (n == 0)
            return true;

        std::queue<size_t> q;
        q.push (0);

        bool should_be_leaf = false;

        while (!q.empty())
        {
            size_t current = q.front();
            q.pop();

            size_t left = 2 * current + 1;
            size_t right = 2 * current + 2;

            if (left < n)
            {
                if (should_be_leaf || arr[left] > arr[current])
                    return false;

                q.push (left);
            }
            else
            {
                should_be_leaf = true;
            }

            if (right < n)
            {
                if (should_be_leaf || arr[right] > arr[current])
                    return false;

                q.push (right);
            }
            else
            {
                should_be_leaf = true;
            }
        }

        return true;
    }
}
