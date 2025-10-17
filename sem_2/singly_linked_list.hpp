#pragma once

#include <iostream>
#include <unordered_set>

namespace lnkd_lst
{
    template<typename T>
    class SListNode
    {
        T data_;
        SListNode<T>* next_;

    public:
        SListNode (const T& value) : data_(value), next_(nullptr) {}
        SListNode (const T& value, SListNode<T>* next_node) : data_(value), next_(next_node) {}

        T get_data() const { return data_; }
        SListNode<T>* get_next() const { return next_; }

        void set_data (const T& value) { data_ = value; }
        void set_next (SListNode<T>* nextNode) { next_ = nextNode; }
    };

    template<typename T>
    class SLinkedList
    {
        SListNode<T>* head_;
        size_t size_;

        void clear()
        {
            if (head_ == nullptr)
            {
                size_ = 0;
                return;
            }

            std::unordered_set<SListNode<T>*> deleted_nodes;
            SListNode<T>* current = head_;
            SListNode<T>* next_node = nullptr;

            while (current != nullptr)
            {
                next_node = current->get_next();

                if (deleted_nodes.count (current))
                {
                    current->set_next (nullptr);
                    break;
                }

                delete current;
                deleted_nodes.insert (current);
                current = next_node;
            }

            head_ = nullptr;
            size_ = 0;
        }

        void copy (const SLinkedList<T>& oth_list)
        {
            clear();

            if (oth_list.empty())
                return;

            SListNode<T>* current = oth_list.head_;
            head_ = new SListNode<T>(current->get_data());

            SListNode<T>* node = head_;

            current = current->get_next();
            while (current != nullptr)
            {
                node->set_next (new SListNode<T>(current->get_data()));
                node = node->get_next();
                current = current->get_next();
                size_++;
            }
        }

    public:
        SLinkedList() : head_(nullptr), size_(0) {}

        ~SLinkedList() { clear(); }

        SLinkedList (const SLinkedList<T>& other) : head_(nullptr), size_(0)
        {
            copy (other);
        }

        SLinkedList<T>& operator= (const SLinkedList<T>& other)
        {
            if (this != &other)
                copy (other);

            return *this;
        }

        SLinkedList (SLinkedList<T>&& other) noexcept : head_(other.head_), size_(other.size_)
        {
            other.head_ = nullptr;
            other.size_ = 0;
        }

        SLinkedList<T>& operator= (SLinkedList<T>&& other) noexcept
        {
            if (this != &other)
            {
                clear();

                head_ = other.head_;
                size_ = other.size_;
                other.head_ = nullptr;
                other.size_ = 0;
            }

            return *this;
        }

        size_t size () const { return size_; }

        bool empty () const { return size_ == 0; }

        SListNode<T>* get_head() { return head_; }

        const SListNode<T>* get_head() const { return head_; }

        void set_head (SListNode<T>* new_head) { head_ = new_head; }

        size_t get_size() const { return size_; }

        void set_size (size_t new_size) { size_ = new_size; }

        void push_front (const T& value)
        {
            SListNode<T>* new_node = new SListNode<T>(value, head_);
            head_ = new_node;
            size_++;
        }

        SListNode<T>* find_node_at (size_t pos)
        {
            if (pos < 1 || pos > size_)
                return nullptr;

            SListNode<T>* current = head_;
            for (size_t i = 1; i < pos; ++i)
            {
                current = current->get_next();
            }
            return current;
        }

        void dump () const
        {
            SListNode<T>* current = head_;

            std::cout << "[";
            while (current != nullptr)
            {
                std::cout << current->get_data();
                if (current->get_next() != nullptr)
                    std::cout << ", ";

                current = current->get_next();
            }
            std::cout << "]" << std::endl;
        }
    };

    template<typename T>
    std::ostream& operator<< (std::ostream& ostrm, const SListNode<T>& node)
    {
        ostrm << node.get_data();
        return ostrm;
    }

    template<typename T>
    std::ostream& operator<< (std::ostream& ostrm, const SLinkedList<T>& list)
    {
        const SListNode<T>* current = list.get_head();

        ostrm << "[";
        while (current != nullptr)
        {
            ostrm << *current;

            if (current->get_next() != nullptr)
                ostrm << ", ";

            current = current->get_next();
        }
        ostrm << "]";

        return ostrm;
    }
}
