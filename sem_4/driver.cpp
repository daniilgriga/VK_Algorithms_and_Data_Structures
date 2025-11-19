#include "algorithms.hpp"

void test_symmetric()
{
    // sym
    std::vector<int> sym_data = {1, 2, 2, 3, 4, 4, 3};
    auto sym_tree = bst::Algorithms<int>::build_tree_from_array (sym_data);

    std::cout << "[2]: syn tree: ";
    for (int val : sym_tree.level_order()) std::cout << val << " ";
    std::cout << std::endl;
    std::cout << "[2]: BFS is_symmetric: " << bst::Algorithms<int>::is_symmetric_bfs (sym_tree) << std::endl;
    std::cout << "[2]: DFS is_symmetric: " << bst::Algorithms<int>::is_symmetric_dfs (sym_tree) << std::endl;

    // asym
    std::vector<int> asym_data = {1, 2, 2, 3, 4, 3, 4};
    auto asym_tree = bst::Algorithms<int>::build_tree_from_array (asym_data);

    std::cout << "[2]: asym tree: ";
    for (int val : asym_tree.level_order()) std::cout << val << " ";
    std::cout << std::endl;
    std::cout << "[2]: BFS is_symmetric: " << bst::Algorithms<int>::is_symmetric_bfs (asym_tree) << std::endl;
    std::cout << "[2]: DFS is_symmetric: " << bst::Algorithms<int>::is_symmetric_dfs (asym_tree) << std::endl;

    sym_tree.save_dot  ("dots/sym_tree_2.dot");
    asym_tree.save_dot ("dots/asym_tree_2.dot");
}

void test_min_depth()
{
    // example 1
    std::vector<int> balanced_data = {1, 2, 3, 4, 5};
    auto balanced_tree = bst::Algorithms<int>::build_tree_from_array (balanced_data);

    std::cout << "[3]: Balance tree: ";
    for (int val : balanced_tree.level_order())
        std::cout << val << " ";
    std::cout << std::endl;
    std::cout << "[3]: Min_depth: " << bst::Algorithms<int>::min_depth (balanced_tree) << std::endl;
    std::cout << std::endl;

    // example 2
    std::vector<int> right_heavy_data = {1, 2, 3, -1, -1, -1, 4};           // -1 for skippings
    auto right_heavy_tree = bst::Algorithms<int>::build_tree_from_array (right_heavy_data);

    std::cout << "[3]: Right heavy tree: ";
    for (int val : right_heavy_tree.level_order())
    {
        if (val != -1)
            std::cout << val << " ";
        else
            std::cout << "null ";
    }
    std::cout << std::endl;
    std::cout << "[3]: Min_depth: " << bst::Algorithms<int>::min_depth (right_heavy_tree) << std::endl;
    std::cout << std::endl;

    // example 3
    std::vector<int> task_data = {11, 16, 9, 6, -1, 13, -1};                // -1 for skippings
    auto task_tree = bst::Algorithms<int>::build_tree_from_array (task_data);

    std::cout << "[3]: Random: ";
    for (int val : task_tree.level_order())
    {
        if (val != -1)
            std::cout << val << " ";
        else
            std::cout << "null ";
    }
    std::cout << std::endl;
    std::cout << "[3]: Min_depth: " << bst::Algorithms<int>::min_depth (task_tree) << std::endl;
    std::cout << std::endl;

    balanced_tree.save_dot ("dots/balanced_tree.dot");
    right_heavy_tree.save_dot ("dots/right_heavy_tree.dot");
    task_tree.save_dot ("dots/task_tree.dot");
}

void test_min_max_mult()
{
    // example 1
    std::vector<int> heap_data = {8, 9, 11, 7, 16, 3, 1};

    std::cout << "[4]: Example 1: ";
    for (int val : heap_data) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "[4]: min * max: " << bst::Algorithms<int>::max_min_mult (heap_data) << std::endl;

    // example 2
    std::vector<int> heap_data2 = {10, 5, 15, 2, 7, 12, 20, 1, 3, 6, 8, 11, 13, 18, 25};
    std::cout << "[4]: Example 2: ";
    for (int val : heap_data2) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "[4]: min * max: " << bst::Algorithms<int>::max_min_mult (heap_data2) << std::endl;
}

void test_tree_equality()
{
    // example 1
    bst::BinaryTree<int> tree1;
    tree1.insert (1);
    tree1.insert (2);

    bst::BinaryTree<int> tree2;
    tree2.insert (1);
    tree2.insert (3);

    std::cout << "[5]: Not the same tree: " << bst::Algorithms<int>::are_trees_equal (tree1, tree2) << std::endl;

    // example 2
    std::vector<int> data = {1, 2, 3, 4, 5};
    auto tree3 = bst::Algorithms<int>::build_tree_from_array (data);
    auto tree4 = bst::Algorithms<int>::build_tree_from_array (data);

    std::cout << "[5]: The same tree: " << bst::Algorithms<int>::are_trees_equal (tree3, tree4) << std::endl;
}



int main ()
{
    // 1.
    std::vector<int> arr = {8, 9, 11, 7, 16, 3, 1};
    bst::BinaryTree<int> tree (arr);
    tree.save_dot ("dots/alg_1.dot");
    std::cout << "[1]: in the \'img/alg_1.png\'" << std::endl;

    // 2.
    test_symmetric();
    std::cout << std::endl;

    // 3.
    test_min_depth();

    // 4.
    test_min_max_mult();
    std::cout << std::endl;

    // 5.
    test_tree_equality();

    return 0;
}
