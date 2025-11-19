#include "algorithms.hpp"

int main ()
{
    // 1.
    std::vector<int> arr = {8, 9, 11, 7, 16, 3, 1};
    bst::BinaryTree<int> tree (arr);

    tree.save_dot ("img/alg_1.dot");

    return 0;
}
