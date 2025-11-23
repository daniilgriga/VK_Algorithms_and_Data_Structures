#include "algorithms.hpp"

#include <iostream>

namespace tst
{
    void test_max_heap ()
    {
        std::vector<int> valid_max_heap = {9, 6, 8, 3, 5, 7, 1};
        std::cout << "[1]:   (1 - max_heap, 0 - unknown) Heap: ";
        for (int val : valid_max_heap) std::cout << val << " ";
        std::cout << std::endl;

        bool status_1 = bst::is_max_heap (valid_max_heap);
        std::cout << "[1.1]: status = " << status_1 << std::endl;

        bool status_2 = bst::is_max_heap_by_bfs (valid_max_heap);
        std::cout << "[1.2]: status = " << status_2 << std::endl;

        bool status_3 = bst::is_max_heap_complete (valid_max_heap);
        std::cout << "[1.3]: status = " << status_3 << std::endl;
    }

    void test_complete_tree ()
    {
        // ex 1
        std::vector<int> complete_tree_vec = {1, 2, 3, 4, 5, 6};
        bst::BinaryTree<int> complete_tree;
        for (int val : complete_tree_vec)
            complete_tree.insert_level_order (val);

        std::cout << "[2]: Complete tree: ";
        auto level_order_1 = complete_tree.level_order();
        for (int val : level_order_1) std::cout << val << " ";
        std::cout << std::endl;

        bool is_complete_1 = bst::Algorithms<int>::is_complete_tree (complete_tree);
        std::cout << "[2]: Is complete tree: " << (is_complete_1 ? "yes" : "no") << std::endl;
        // ex 2
        bst::BinaryTree<int> tree;
        bst::Algorithms<int>::make_incmpl_tree (tree);

        std::cout << "[2]: Incomplete tree: ";
        auto level_order_2 = tree.level_order();
        for (int val : level_order_2) std::cout << val << " ";
        std::cout << std::endl;

        bool is_complete_2 = bst::Algorithms<int>::is_complete_tree (tree);
        std::cout << "[2]: Is complete tree: " << (is_complete_2 ? "yes" : "no") << std::endl;

    }
}

int main ()
{
    tst::test_max_heap();
    tst::test_complete_tree();

    return 0;
}
