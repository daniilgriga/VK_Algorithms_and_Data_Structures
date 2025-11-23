#pragma once

#include "bstree.hpp"
#include <vector>
#include <queue>

namespace bst
{
    template<typename T>
    class Algorithms
    {
    public:
        // 1.
        static BinaryTree<T> build_tree_from_array (const std::vector<T>& arr)
        {
            return BinaryTree<T>(arr);
        }

        // 2.
        static bool is_symmetric_bfs (const BinaryTree<T>& tree)
        {
            if (tree.root_ == nullptr)
                return true;

            std::queue<typename BinaryTree<T>::Node*> q;
            q.push (tree.root_);

            while (!q.empty())
            {
                size_t q_len = q.size();

                std::vector<typename BinaryTree<T>::Node*> current_level;

                for (size_t i = 0; i < q_len; i++)
                {
                    typename BinaryTree<T>::Node* node = q.front();
                    q.pop();
                    current_level.push_back (node);

                    if (node != nullptr)
                    {
                        q.push (node->left());
                        q.push (node->right());
                    }
                }

                for (size_t i = 0; i < q_len; i++)
                {
                    size_t sym_index = q_len - i - 1;

                    typename BinaryTree<T>::Node* node1 = current_level[i];
                    typename BinaryTree<T>::Node* node2 = current_level[sym_index];

                    if (node1 == nullptr && node2 == nullptr)
                        continue;

                    if (node1 == nullptr || node2 == nullptr)
                        return false;

                    if (node1->data() != node2->data())
                        return false;
                }
            }

            return true;
        }

        static bool is_symmetric_dfs (const BinaryTree<T>& tree)
        {
            if (tree.root_ == nullptr)
                return true;

            std::vector<T> data;
            depth_search_inorder (tree.root_, data);

            size_t j = data.size() - 1;

            for (size_t i = 0; i < data.size() / 2; i++)
            {
                if (data[i] != data[j])
                    return false;

                j--;
            }

            return true;
        }

        static void depth_search_inorder (typename BinaryTree<T>::Node* node, std::vector<T>& data)
        {
            if (node == nullptr)
                return;

            depth_search_inorder (node->left(), data);
            data.push_back (node->data());
            depth_search_inorder (node->right(), data);
        }

        // 3.
        static size_t min_depth (const BinaryTree<T>& tree)
        {
            return min_depth_rec (tree.root_);
        }

        static size_t min_depth_rec (typename BinaryTree<T>::Node* root)
        {
            if (root == nullptr)
                return 0;

            if (root->left() == nullptr && root->right() == nullptr)
                return 1;

            if (root->left() != nullptr && root->right() != nullptr)
                return 1 + std::min (min_depth_rec (root->left()),
                                     min_depth_rec (root->right()));

            if (root->left() != nullptr)
                return 1 + min_depth_rec (root->left());

            if (root->right() != nullptr)
                return 1 + min_depth_rec (root->right());

            return 1;       // plug
        }

        // 4.
        static T max_min_mult (const std::vector<T>& data)
        {
            if (data.size() < 3)
                return -1;

            size_t min_index = 1;
            for (size_t i = 1; i < data.size(); i = 2 * i + 1)
                min_index = i;

            size_t max_index = 2;
            for (size_t i = 2; i < data.size(); i = 2 * i + 2)
                max_index = i;

            return data[min_index] * data[max_index];
        }

        // 5.
        static bool are_trees_equal (const BinaryTree<T>& tree1, const BinaryTree<T>& tree2)
        {
            return is_same_tree (tree1.root_, tree2.root_);
        }

        static bool is_same_tree (typename BinaryTree<T>::Node* a,
                                  typename BinaryTree<T>::Node* b)
        {
            if (a == nullptr && b == nullptr)
                return true;

            if (a == nullptr || b == nullptr)
                return false;

            if (a->data() != b->data())
                return false;

            return (is_same_tree (a->left(), b->left()) &&
                    is_same_tree (a->right(), b->right()));
        }
    };
} // namespace bst
