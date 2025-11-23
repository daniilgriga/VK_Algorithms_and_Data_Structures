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

        bool status_1 = algs::is_max_heap (valid_max_heap);
        std::cout << "[1.1]: status = " << status_1 << std::endl;

        bool status_2 = algs::is_max_heap_by_bfs (valid_max_heap);
        std::cout << "[1.2]: status = " << status_2 << std::endl;

        bool status_3 = algs::is_max_heap_complete (valid_max_heap);
        std::cout << "[1.3]: status = " << status_3 << std::endl;
    }
}

int main ()
{
    tst::test_max_heap();

    return 0;
}
