#pragma once

#include <queue>
#include <stack>
#include <cctype>

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

    // 5.1.
    bool is_subsequence_queue (const std::string& a, const std::string& b)
    {
        if (a.empty())
            return true;
        if (b.empty())
            return false;

        std::queue<char> queue;

        for (char ch : a)
            queue.push (ch);

        for (char ch : b)
        {
            if (queue.empty())
                break;

            if (queue.front() == ch)
                queue.pop();
        }

        return queue.empty();
    }

    // 5.2.
    bool is_subsequence_pointers (const std::string& a, const std::string& b)
    {
        if (a.empty())
            return true;
        if (b.empty())
            return false;

        size_t i = 0;
        size_t j = 0;

        while (i < a.length() && j < b.length())
        {
            if (a[i] == b[j])
                i++;

            j++;
        }

        return i == a.length();
    }

    // 6.
    char to_lower_symb (char c)     // to only one lower register
    {
        return std::tolower (static_cast<unsigned char>(c));
    }

    bool is_alpha_or_num (char c)   // check only letter and nums
    {
        return std::isalnum (static_cast<unsigned char>(c));
    }

    // 6.1.
    bool is_palindrome_stack (const std::string& str)
    {
        if (str.empty())
            return true;

        std::stack<char> stack;

        for (char ch : str)
        {
            if (is_alpha_or_num (ch))
                stack.push (to_lower_symb (ch));
        }

        for (char ch : str)
        {
            if (is_alpha_or_num (ch))
            {
                if (to_lower_symb (ch) != stack.top())
                    return false;

                stack.pop();
            }
        }

        return true;
    }

    // 6.2.
    bool is_palindrome_deque (const std::string& str)
    {
        if (str.empty())
            return true;

        std::deque<char> deque;

        for (char ch : str)
        {
            if (is_alpha_or_num (ch))
                deque.push_back (to_lower_symb (ch));
        }

        while (deque.size() > 1)
        {
            if (deque.front() != deque.back())
                return false;

            deque.pop_front();
            deque.pop_back();
        }

        return true;
    }

    // 6.3.
    bool is_palindrome_pointers (const std::string& str)
    {
        if (str.empty())
            return true;

        int left = 0;
        int right = str.length() - 1;

        while (left < right)
        {
            while (left < right && !is_alpha_or_num (str[left]))
                left++;

            while (left < right && !is_alpha_or_num (str[right]))
                right--;

            if (to_lower_symb (str[left]) != to_lower_symb (str[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }

    // 7.
    lnkd_lst::SLinkedList<int> merge_sorted_lists (lnkd_lst::SLinkedList<int>& list1,
                                                   lnkd_lst::SLinkedList<int>& list2)
    {
        if (list1.empty())
            return std::move (list2);
        if (list2.empty())
            return std::move (list1);

        auto node1 = list1.get_head();
        auto node2 = list2.get_head();

        auto head = (node1->get_data() <= node2->get_data()) ? node1 : node2;
        auto tail = head;

        if (head == node1)
            node1 = node1->get_next();
        else
            node2 = node2->get_next();

        while (node1 != nullptr && node2 != nullptr)
        {
            if (node1->get_data() <= node2->get_data())
            {
                tail->set_next (node1);
                node1 = node1->get_next();
            }
            else
            {
                tail->set_next (node2);
                node2 = node2->get_next();
            }

            tail = tail->get_next();
        }

        tail->set_next (node1 ? node1 : node2);

        lnkd_lst::SLinkedList<int> merged_l;

        merged_l.set_head (head);
        merged_l.set_size (list1.size() + list2.size());

        list1.set_head (nullptr); list1.set_size (0);
        list2.set_head (nullptr); list2.set_size (0);

        return merged_l;
    }
}
