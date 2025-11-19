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
        static bool is_symmetric (const BinaryTree<T>& tree)
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
    };
} // namespace bst
