#include "algorithms.hpp"

void test_symmetric()
{
    // sym
    std::vector<int> sym_data = {1, 2, 2, 3, 4, 4, 3};
    auto sym_tree = bst::Algorithms<int>::build_tree_from_array (sym_data);

    std::cout << "syn tree: ";
    for (int val : sym_tree.level_order()) std::cout << val << " ";
    std::cout << std::endl;
    std::cout << "is_symmetric: " << bst::Algorithms<int>::is_symmetric (sym_tree) << std::endl;

    // asym
    std::vector<int> asym_data = {1, 2, 2, 3, 4, 3, 4};
    auto asym_tree = bst::Algorithms<int>::build_tree_from_array (asym_data);

    std::cout << "asym tree: ";
    for (int val : asym_tree.level_order()) std::cout << val << " ";
    std::cout << std::endl;
    std::cout << "is_symmetric: " << bst::Algorithms<int>::is_symmetric (asym_tree) << std::endl;

    sym_tree.save_dot  ("dots/sym_tree_2.dot");
    asym_tree.save_dot ("dots/asym_tree_2.dot");
}


int main ()
{
    // 1.
    std::vector<int> arr = {8, 9, 11, 7, 16, 3, 1};
    bst::BinaryTree<int> tree (arr);

    tree.save_dot ("dots/alg_1.dot");

    // 2.
    test_symmetric();


    return 0;
}
