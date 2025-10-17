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

    // 2.
    template<typename T>
    void reverse_linked_list (lnkd_lst::SLinkedList<T>& list)
    {
        auto head = list.get_head();
        if (head == nullptr || head->get_next() == nullptr)
            return;

        lnkd_lst::SListNode<T>* prev = nullptr;
        lnkd_lst::SListNode<T>* current = head;
        lnkd_lst::SListNode<T>* next = nullptr;

        while (current != nullptr)
        {
            next = current->get_next();
            current->set_next (prev);
            prev = current;
            current = next;
        }

        list.set_head (prev);
    }

    // 3.
    template<typename T>
    const lnkd_lst::SListNode<T>* search_middle_node (const lnkd_lst::SLinkedList<T>& list)
    {
        auto slow = list.get_head();
        if (slow == nullptr)
            return nullptr;

        auto fast = slow;

        while (fast != nullptr && fast->get_next() != nullptr)
        {
            slow = slow->get_next();
            fast = fast->get_next()->get_next();
        }

        return slow;
    }
}

