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

    // 4.
    template<typename T>
    void remove_elements (lnkd_lst::SLinkedList<T>& list, const T& value)
    {
        auto head = list.get_head();
        if (head == nullptr)
            return;

        lnkd_lst::SListNode<T> dummy (T{});                 // works only when T have ctor
        dummy.set_next (head);

        lnkd_lst::SListNode<T>* prev = &dummy;
        lnkd_lst::SListNode<T>* current = head;

        size_t del_cnt = 0;

        while (current != nullptr)
        {
            if (current->get_data() == value)
            {
                prev->set_next (current->get_next());
                delete current;
                current = prev->get_next();

                del_cnt++;
            }
            else
            {
                prev = current;
                current = current->get_next();
            }
        }

        list.set_head (dummy.get_next());
        list.set_size (list.get_size() - del_cnt);
    }
}

