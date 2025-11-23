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

    void test_merged_arr ()
    {
        std::vector<std::vector<int>> arrays = { {1, 4, 5},
                                                 {1, 3, 4},
                                                 {2, 6}    };

        auto result_1 = bst::Algorithms<int>::merge_k_sorted_arrays_simple (arrays);
        auto result_2 = bst::Algorithms<int>::merge_k_sorted_arrays_advanced (arrays);

        std::cout << "[3]: Input arrays:" << std::endl;
        for (const auto& arr : arrays)
        {
            for (int val : arr) std::cout << val << " ";
            std::cout << std::endl;
        }

        std::cout << "[3.1]: Merged result_1: ";
        for (int val : result_1) std::cout << val << " ";
        std::cout << std::endl;

        bool is_sorted = true;
        for (size_t i = 1; i < result_1.size(); ++i)
            if (result_1[i] < result_1[i-1])
            {
                is_sorted = false;
                break;
            }

        std::cout << "[3.1]: Is correctly sorted: " << (is_sorted ? "yes" : "no") << std::endl;
        std::cout << "[3.1]: Total elements: " << result_1.size() << std::endl;

        std::cout << "[3.2]: Merged result_2: ";
        for (int val : result_2) std::cout << val << " ";
        std::cout << std::endl;

        is_sorted = true;
        for (size_t i = 1; i < result_2.size(); ++i)
            if (result_2[i] < result_2[i-1])
            {
                is_sorted = false;
                break;
            }

        std::cout << "[3.2]: Is correctly sorted: " << (is_sorted ? "yes" : "no") << std::endl;
        std::cout << "[3.2]: Total elements: " << result_2.size() << std::endl;
    }

    void test_k_smallest ()
    {
        bst::BinaryTree<int> tree;
        tree.insert (5);
        tree.insert (3);
        tree.insert (7);
        tree.insert (2);
        tree.insert (4);
        tree.insert (8);

        auto inorder = tree.inorder();
        std::cout << "[4]: Inorder traversal: ";
        for (int val : inorder)
            std::cout << val << " ";
        std::cout << std::endl;

        std::cout << "[4]: 1st smallest: " << bst::Algorithms<int>::k_smallest (tree, 1) << std::endl;
        std::cout << "[4]: 2nd smallest: " << bst::Algorithms<int>::k_smallest (tree, 2) << std::endl;
        std::cout << "[4]: 3rd smallest: " << bst::Algorithms<int>::k_smallest (tree, 3) << std::endl;
        std::cout << "[4]: 4th smallest: " << bst::Algorithms<int>::k_smallest (tree, 4) << std::endl;
        std::cout << "[4]: 5th smallest: " << bst::Algorithms<int>::k_smallest (tree, 5) << std::endl;
        std::cout << "[4]: 6th smallest: " << bst::Algorithms<int>::k_smallest (tree, 6) << std::endl;
    }

    void test_balance_factor ()
    {
        bst::BinaryTree<int> tree;
        tree.insert (5);
        tree.insert (3);
        tree.insert (7);
        tree.insert (2);
        tree.insert (4);
        tree.insert (8);

        std::cout << "[5]: tree: ";
        auto level_order = tree.level_order();
        for (int val : level_order) std::cout << val << " ";
        std::cout << std::endl;

        int tree_height = bst::Algorithms<int>::calculate_heights_and_balance (tree);
        std::cout << "[5]: tree height = " << tree_height << std::endl;
    }
}

int main ()
{
    tst::test_max_heap();
    tst::test_complete_tree();
    tst::test_merged_arr();
    tst::test_k_smallest();
    tst::test_balance_factor();

    return 0;
}
