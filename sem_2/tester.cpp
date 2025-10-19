#include "algorithms.hpp"

namespace lnkd_lst
{
    template<typename T>
    int create_cycle_in_list(SLinkedList<T>& list, size_t pos)
    {
        if (list.empty())
        {
            std::cout << "in [1]: List is empty." << std::endl;
            return 1;
        }

        SListNode<T>* cycle_start = list.find_node_at (pos);
        if (cycle_start == nullptr)
        {
            std::cout << "in [1]: Wrong position for cycle: " << pos << std::endl;
            return 1;
        }

        SListNode<T>* tail = list.get_head();
        while (tail->get_next() != nullptr)
            tail = tail->get_next();

        tail->set_next (cycle_start);
        std::cout << "in [1]: Cycle created at position " << pos << std::endl;

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
    List.push_front (10);
    List.push_front (80);

    List.dump();

    // 1.
    lnkd_lst::SLinkedList<int> cycle_lst = List;
    if (lnkd_lst::create_cycle_in_list (cycle_lst, 5))
        return 1;

    if (algs::cycle_search (cycle_lst))
        std::cout << "[1]: is cycled list" << std::endl;
    else
        std::cout << "[1]: is common list" << std::endl;

    // 2.
    algs::reverse_linked_list (List);
    std::cout << "[2]: after reverse: ";
    List.dump();
    std::cout << "[2]: head after reverse: " << List.get_head()->get_data() << std::endl;

    // 3.
    auto mid_node = algs::search_middle_node (List);
    std::cout << "[3]: mid_node = " << mid_node << ", data = " << *mid_node << std::endl;

    // 4.
    std::cout << "[4]: size = " << List.get_size();
    algs::remove_elements (List, 10);
    std::cout << " | remove '10' -> size = " << List.get_size() << ": ";
    List.dump();
    std::cout << "\n";

    // 5.
    const std::string a = "lgots";
    const std::string b = "Algorithms";
    // 5.1.
    if (algs::is_subsequence_queue (a, b))
        std::cout << "[5.1 (queue)]:    a = '" << a << "' is a substring of b = '" << b << "'" << std::endl;
    else
        std::cout << "[5.1 (queue)]:    a = '" << a << "' is NOT a substring of b = '" << b << "'" << std::endl;
    // 5.2.
    if (algs::is_subsequence_pointers (a, b))
        std::cout << "[5.2 (pointers)]: a = '" << a << "' is a substring of b = '" << b << "'\n" << std::endl;
    else
        std::cout << "[5.2 (pointers)]: a = '" << a << "' is NOT a substring of b = '" << b << "'\n" << std::endl;

    // 6.
    const std::string str_1 = "Oozy 38 rat in a sanitar 83 y zoo";
    const std::string str_2 = "levelt";

    const std::string string = str_1;
    // 6.1.
    if (algs::is_palindrome_stack (string))
        std::cout << "[6.1 (stack)]:    string = '" << string << "' is a palindrom!" << std::endl;
    else
        std::cout << "[6.1 (stack)]:    string = '" << string << "' is NOT a palindrom!" << std::endl;
    // 6.2.
    if (algs::is_palindrome_deque (string))
        std::cout << "[6.2 (deque)]:    string = '" << string << "' is a palindrom!" << std::endl;
    else
        std::cout << "[6.2 (deque)]:    string = '" << string << "' is NOT a palindrom!" << std::endl;
    // 6.3.
    if (algs::is_palindrome_pointers (string))
        std::cout << "[6.3 (pointers)]: string = '" << string << "' is a palindrom!\n" << std::endl;
    else
        std::cout << "[6.3 (pointers)]: string = '" << string << "' is NOT a palindrom!\n" << std::endl;

    return 0;
}
