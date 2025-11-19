#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>

namespace bst
{
    template<typename T>
    class BinaryTree
    {
    private:
        class Node
        {
        private:
            T data_;
            Node* left_;
            Node* right_;

        public:
            explicit Node(const T& data, Node* left = nullptr, Node* right = nullptr)
                : data_(data), left_(left), right_(right) {}

            explicit Node(T&& data, Node* left = nullptr, Node* right = nullptr)
                : data_(std::move(data)), left_(left), right_(right) {}

            Node(const Node& other)
                : data_(other.data_), left_(nullptr), right_(nullptr) {}

            const T& data() const { return data_; }
            T& data() { return data_; }

            const Node* left() const { return left_; }
            Node* left() { return left_; }

            const Node* right() const { return right_; }
            Node* right() { return right_; }


            void set_left (Node* left) { left_ = left; }
            void set_right (Node* right) { right_ = right; }
            void set_data (const T& data) { data_ = data; }

            friend class BinaryTree;
        };

        Node* root_;
        size_t size_;

        void clear_tree (Node* node)
        {
            if (node == nullptr)
                return;

            std::vector<Node*> vec;
            vec.push_back (node);

            while (!vec.empty())
            {
                Node* current = vec.back();
                vec.pop_back();

                Node* left = current->left();
                if (left)
                    vec.push_back (left);

                Node* right = current->right();
                if (right)
                    vec.push_back (right);

                delete current;
            }
        }

        Node* copy_subtree (const Node* node)
        {
            if (node == nullptr)
                return nullptr;

            Node* new_node = new Node(node->data());

            new_node->set_left (copy_subtree (node->left()));
            new_node->set_right (copy_subtree (node->right()));

            return new_node;
        }

        Node* insert_data (const T& data)
        {
            if (root_ == nullptr)
            {
                size_++;
                root_ = new Node(data);

                return root_;
            }

            Node* curr = root_;
            Node* parent = nullptr;

            while (curr != nullptr)
            {
                parent = curr;

                if (data < curr->data())
                    curr = curr->left();
                else if (data > curr->data())
                    curr = curr->right();
                else
                    return curr;
            }

            Node* new_node = new Node(data);
            if (data < parent->data())
                parent->set_left (new_node);
            else
                parent->set_right (new_node);

            size_++;

            return new_node;
        }

    public:
        BinaryTree() : root_(nullptr), size_(0) {}

        ~BinaryTree()
        {
            clear_tree(root_);
        }

        BinaryTree(const BinaryTree& other)
            : root_(copy_subtree(other.root_)), size_(other.size_) {}

        BinaryTree(BinaryTree&& other) noexcept
            : root_(other.root_), size_(other.size_)
        {
            other.root_ = nullptr;
            other.size_ = 0;
        }

        BinaryTree& operator= (const BinaryTree& other)
        {
            if (this != &other)
            {
                clear_tree (root_);
                root_ = copy_subtree (other.root_);
                size_ = other.size_;
            }

            return *this;
        }

        BinaryTree& operator= (BinaryTree&& other) noexcept
        {
            if (this != &other)
            {
                clear_tree (root_);

                root_ = other.root_;
                size_ = other.size_;

                other.root_ = nullptr;
                other.size_ = 0;
            }

            return *this;
        }

        bool empty()  const noexcept { return size_ == 0; }
        size_t size() const noexcept { return size_; }

        const Node* root() const { return root_; }
        Node* root() { return root_; }

        void insert (const T& data)
        {
            insert_data (data);
        }

        bool contains (const T& data) const
        {
            Node* curr = root_;
            while (curr != nullptr)
            {
                if (data == curr->data())
                    return true;
                else if (data < curr->data())
                    curr = curr->left();
                else
                    curr = curr->right();
            }

            return false;
        }

        // BFS
        std::vector<T> level_order() const
        {
            std::vector<T> result;

            if (root_ == nullptr)
                return result;

            std::queue<Node*> q;
            q.push(root_);

            while (!q.empty())
            {
                Node* current = q.front();
                q.pop();

                result.push_back (current->data());

                if (current->left())
                    q.push (current->left());

                if (current->right())
                    q.push (current->right());
            }

            return result;
        }

        // inorder
        std::vector<T> inorder() const
        {
            std::vector<T> result;
            std::stack<Node*> s;

            Node* curr = root_;

            while (curr != nullptr || !s.empty())
            {
                while (curr != nullptr)
                {
                    s.push (curr);
                    curr = curr->left();
                }

                curr = s.top();
                s.pop();

                result.push_back (curr->data());
                curr = curr->right();
            }

            return result;
        }

        const Node* min_node() const
        {
            if (root_ == nullptr)
                return nullptr;

            Node* curr = root_;

            while (curr->left() != nullptr)
                curr = curr->left();

            return curr;
        }

        const Node* max_node() const
        {
            if (root_ == nullptr)
                return nullptr;

            Node* curr = root_;

            while (curr->right() != nullptr)
                curr = curr->right();

            return curr;
        }

        void save_dot (const std::string& filename) const
        {
            std::ofstream file(filename);
            file << "digraph BinaryTree {\n";
            file << "    node [shape=circle];\n";

            if (root_ != nullptr)
            {
                std::queue<Node*> q;
                q.push (root_);

                while (!q.empty())
                {
                    Node* current = q.front();
                    q.pop();

                    file << "    \"" << current << "\" [label=\"" << current->data() << "\"];\n";

                    if (current->left())
                    {
                        file << "    \"" << current << "\" -> \"" << current->left() << "\" [label=\"L\"];\n";
                        q.push (current->left());
                    }

                    if (current->right())
                    {
                        file << "    \"" << current << "\" -> \"" << current->right() << "\" [label=\"R\"];\n";
                        q.push (current->right());
                    }
                }
            }
            else
            {
                file << "    empty [label=\"Empty Tree\"];\n";
            }


            file << "}\n";
            file.close();
        }
    };

} // namespace bst

