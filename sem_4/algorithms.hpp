#include "bstree.hpp"

namespace algs
{
    // 1.
    template<typename T>
    bst::BinaryTree<T> build_tree_from_array (const std::vector<T>& arr)
    {
        return bst::BinaryTree<T>(arr); // constructor in the BinaryTree class
    }

} // namespace algs
