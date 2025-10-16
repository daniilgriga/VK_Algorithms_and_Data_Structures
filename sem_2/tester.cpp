#include "algorithms.hpp"

namespace lnkd_lst
{
    template<typename T>
    int create_cycle_in_list(SLinkedList<T>& list, size_t pos)
    {
        if (list.empty())
        {
            std::cout << "List is empty." << std::endl;
            return 1;
        }

        SListNode<T>* cycle_start = list.find_node_at (pos);
        if (cycle_start == nullptr)
        {
            std::cout << "Wrong position for cycle: " << pos << std::endl;
            return 1;
        }

        SListNode<T>* tail = list.get_head();
        while (tail->get_next() != nullptr)
            tail = tail->get_next();

        tail->set_next (cycle_start);
        std::cout << "Cycle created at position " << pos << std::endl;

        return 0;
    }
}

int main ()
{
    lnkd_lst::SLinkedList<int> List;
    List.push_front (10);
    List.push_front (20);
    List.push_front (30);
    List.push_front (35);
    List.push_front (40);
    List.push_front (50);
    List.push_front (60);
    List.push_front (70);
    List.push_front (80);

    List.dump();

    lnkd_lst::SLinkedList<int> cycle_lst = List;
    if (lnkd_lst::create_cycle_in_list (cycle_lst, 5))
        return 1;

    if (algs::cycle_search (cycle_lst))
        std::cout << "1: is cycled list" << std::endl;
    else
        std::cout << "1: is common list" << std::endl;

    return 0;
}
