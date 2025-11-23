#pragma once

#include <vector>
#include <queue>

#include "bstree.hpp"

namespace bst
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

    template<typename T>
    class Algorithms
    {
    public:
        // 2.
        static bool is_complete_tree (const bst::BinaryTree<T>& tree)
        {
            if (tree.empty())
                return true;

            std::queue<const typename bst::BinaryTree<T>::Node*> q;
            q.push (tree.root());

            bool should_be_leaf = false;

            while (!q.empty())
            {
                const typename bst::BinaryTree<T>::Node* current = q.front();
                q.pop();

                if (current == nullptr)
                {
                    should_be_leaf = true;
                }
                else
                {
                    if (should_be_leaf)
                        return false;

                    q.push (current->left());
                    q.push (current->right());
                }
            }

            return true;
        }

        static void make_incmpl_tree (bst::BinaryTree<T>& tree)
        {
            tree.clear_tree (tree.root());

            auto* root = new typename bst::BinaryTree<T>::Node(10);
            auto* left = new typename bst::BinaryTree<T>::Node(5);
            auto* right = new typename bst::BinaryTree<T>::Node(15);
            auto* right_left = new typename bst::BinaryTree<T>::Node(12);

            root->set_left (left);
            root->set_right (right);
            right->set_left (right_left);

            tree.root_ = root;
            tree.size_ = 4;

            left->set_parent (root);
            right->set_parent (root);
            right_left->set_parent (right);
        }
    };
}
