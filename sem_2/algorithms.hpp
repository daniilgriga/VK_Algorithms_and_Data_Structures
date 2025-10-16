#pragma once

#include "singly_linked_list.hpp"

namespace algs
{
    // 1.
    template<typename T>
    bool cycle_search (const lnkd_lst::SLinkedList<T>& list)
    {
        if (list.empty())
            return false;

        auto slow = list.get_head();
        auto fast = list.get_head()->get_next();

        while (fast != nullptr && fast->get_next() != nullptr)
        {
            slow = slow->get_next();
            fast = fast->get_next()->get_next();

            if (slow == fast)
                return true;
        }

        return false;
    }
}

