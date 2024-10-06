#include <iostream>
#include <memory>
#include <limits>

template <typename T = int>
struct Node
{
    T value;
    Node *prev;
    Node *next;

    Node() : value{}, prev(nullptr), next(nullptr)
    {
    }

    Node(const T value) : Node()
    {
        this->value = value;
    }

    constexpr void resetLinks()
    {
        prev = next = nullptr;
    }
};

template <typename T = int>
class LinkedList
{
private:
    T deleteNode(Node<T> *node)
    {
        if (node == nullptr)
        {
            throw std::runtime_error("Invalid node to delete");
        }

        auto previous = node->prev;
        auto next = node->next;
        if (previous != nullptr)
        {
            previous->next = next;
        }
        if (next != nullptr)
        {
            next->prev = previous;
        }
        node->resetLinks();
        const auto del_val = node->value;
        delete node;
        --size;

        return del_val;
    }

    int size;
    Node<T> *first;
    Node<T> *last;

public:
    LinkedList() noexcept : size(0)
    {
        first = last = nullptr;
    }

    LinkedList(const LinkedList &) = delete;

    ~LinkedList()
    {
        clear();
    }

    void addLast(const T &value)
    {
        Node<T> *node = new Node(value);
        if (isEmpty())
        {
            first = last = node;
        }
        else
        {
            last->next = node;
            node->prev = last;
            last = node;
        }
        ++size;
    }

    void addFirst(const T &value)
    {
        Node<T> *node = new Node(value);
        if (isEmpty())
        {
            first = last = node;
        }
        else
        {
            node->next = first;
            first->prev = node;
            first = node;
        }
        ++size;
    }

    void addAt(const int index, const T &value)
    {
        if (index < 0)
        {
            throw std::invalid_argument("Invalid index: " + std::to_string(index) + '\n');
        }
        else if (index > size)
        {
            throw std::invalid_argument("Invalid index: " + std::to_string(index) + ", greater than list size: " + std::to_string(size) + '\n');
        }
        if (index == 0)
        {
            addFirst(value);
        }
        else if (index == size)
        {
            addLast(value);
        }
        else
        {
            Node<T> *node = new Node(value);
            unsigned idx = 0;
            Node<T> *current = nullptr;
            if (index <= size / 2)
            {
                current = first;
                while (current != nullptr && idx < index)
                {
                    current = current->next;
                    ++idx;
                }
            }
            else
            {
                idx = size - 1;
                current = last;
                while (current != nullptr && idx > index)
                {
                    current = current->prev;
                    --idx;
                }
            }
            if (current == nullptr)
            {
                delete node;
                throw std::bad_variant_access();
            }
            auto previous = current->prev;
            previous->next = node;
            current->prev = node;
            node->prev = previous;
            node->next = current;
            ++size;
        }
    }

    int indexOf(const T &value) const
    {
        unsigned index = 0;
        auto current = first;
        while (current != nullptr && current->value != value)
        {
            current = current->next;
            ++index;
        }
        return (current != nullptr) ? index : -1;
    }

    bool contains(const T &value) const
    {
        const auto index_of = indexOf(value);
        return (index_of >= 0);
    }

    constexpr int getSize() const noexcept
    {
        return size;
    }

    constexpr bool isEmpty() const noexcept
    {
        return size == 0;
    }

    const T removeFirst()
    {
        if (isEmpty())
        {
            throw std::runtime_error("This list is empty, unable to remove the first item\n");
        }
        const auto first_value = first->value;
        if (first == last)
        {
            first->resetLinks();
            delete first;
            first = last = nullptr;
        }
        else
        {
            auto second_node = first->next;
            second_node->prev = nullptr;
            first->resetLinks();
            delete first;
            first = second_node;
        }
        --size;

        return first_value;
    }

    const T removeLast()
    {
        if (isEmpty())
        {
            throw std::runtime_error("This list is empty, unable to remove the last item\n");
        }
        const auto last_value = last->value;
        if (first == last)
        {
            last->resetLinks();
            delete last;
            first = last = nullptr;
        }
        else
        {
            auto previous = last->prev;
            previous->next = nullptr;
            last->resetLinks();
            delete last;
            last = previous;
        }
        --size;

        return last_value;
    }

    int remove(const T &value)
    {
        if (isEmpty())
        {
            throw std::runtime_error("This list is empty, unable to remove node: " + std::to_string(value) + '\n');
        }
        unsigned index = 0;
        if (first->value == value)
        {
            removeFirst();
            return index;
        }
        auto current = first;
        while (current != nullptr && current->value != value)
        {
            current = current->next;
            ++index;
        }
        if (current == last)
        {
            removeLast();
            return index;
        }
        if (current == nullptr)
        {
            throw std::invalid_argument("Unable to remove value: " + std::to_string(value) + ", not found\n");
        }
        try
        {
            deleteNode(current);
        }
        catch (const std::exception &e)
        {
            throw;
        }

        return index;
    }

    const T removeAt(const int index)
    {
        if (isEmpty())
        {
            throw std::runtime_error("This list is empty, unable to remove node at position: " + std::to_string(index) + '\n');
        }
        if (index == 0)
        {
            return removeFirst();
        }
        if (index == size - 1)
        {
            return removeLast();
        }
        Node<T> *current = nullptr;
        unsigned idx = 0;
        if (index <= size / 2)
        {
            current = first;
            idx = 0;
            while (current != last && idx < index)
            {
                current = current->next;
                ++idx;
            }
        }
        else
        {
            current = last;
            idx = size - 1;
            while (current != first && idx > index)
            {
                current = current->prev;
                --idx;
            }
        }
        T del_val{};
        try
        {
            del_val = deleteNode(current);
        }
        catch (const std::exception &e)
        {
            throw;
        }

        return del_val;
    }

    std::unique_ptr<T[]> toArray() const
    {
        std::unique_ptr<T[]> int_arr = std::make_unique<T[]>(size);
        unsigned idx = 0;
        for (auto current = first; current != nullptr; current = current->next)
        {
            int_arr[idx++] = current->value;
        }
        return int_arr;
    }

    const T &getKthNodeFromTheEnd(const int k) const
    {
        if (k < 1 || k > size)
        {
            throw std::runtime_error("Invalid argument: " + std::to_string(k) + " to get an item, argument must be in: [" + std::to_string(1) + '-' + std::to_string(size) + "]\n");
        }
        if (isEmpty())
        {
            throw std::runtime_error("The list is empty");
        }
        if (k == 1)
        {
            return last->value;
        }
        auto current = last;
        for (auto diff = k - 1; diff >= 1 && current != nullptr; --diff)
        {
            current = current->prev;
        }
        if (current == nullptr)
        {
            throw std::runtime_error("Passed the list while setting the difference!");
        }

        return current->value;
    }

    const T &getAt(const int index) const
    {
        if (index < 0 || index >= size)
        {
            throw std::runtime_error("Invalid argument: " + std::to_string(index) + " to get an item, argument must be in: [" + std::to_string(0) + '-' + std::to_string(size - 1) + "]\n");
        }
        if (isEmpty())
        {
            throw std::runtime_error("The list is empty");
        }
        if (index == 0)
        {
            return first->value;
        }
        if (index == size - 1)
        {
            return last->value;
        }
        Node<T> *current = nullptr;
        if (index < size / 2)
        {
            current = first->next;
            for (auto idx = 1; idx < index && current != last; ++idx)
            {
                current = current->next;
            }
        }
        else
        {
            current = last->prev;
            for (auto idx = size - 1; idx > index && current != first; --idx)
            {
                current = current->prev;
            }
        }
        if (current == first || current == last)
        {
            throw std::runtime_error("Passed the list while searching for the index: " + std::to_string(index) + '\n');
        }

        return current->value;
    }

    void reverse()
    {
        if (isEmpty() || first == last)
        {
            return;
        }
        auto current = last;
        auto previous = current->prev;
        while (current != nullptr)
        {
            current->prev = current->next;
            current->next = previous;
            current = previous;
            if (previous != nullptr)
            {
                previous = previous->prev;
            }
        }
        current = first;
        first = last;
        last = current;
    }

    const std::string toString() const
    {
        std::string list_str("[");
        for (auto node = first; node != nullptr; node = node->next)
        {
            list_str += std::to_string(node->value);
            if (node->next != nullptr)
            {
                list_str += ", ";
            }
        }
        list_str += "]";

        return list_str;
    }

    void clear()
    {
        unsigned count = 0;
        if (!isEmpty())
        {
            auto current = first;
            auto next = current->next;
            while (current != nullptr)
            {
                current->prev = current->next = nullptr;
                delete current;
                current = next;
                if (next != nullptr)
                {
                    next = current->next;
                }
                ++count;
            }
            size -= count;
            std::cout << count << " nodes deleted, size of the list: " << size << '\n';
            first = last = nullptr;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const LinkedList<T> &linkedList)
    {
        for (auto current = linkedList.first; current != nullptr; current = current->next)
        {
            os << current->value << '\n';
        }

        return os;
    }

    class Iterator
    {
    public:
        Iterator() noexcept : m_pCurrentNode(nullptr)
        {
        }

        Iterator(const Node<T> *pNode) noexcept : m_pCurrentNode(pNode)
        {
        }

        Iterator &operator=(const Node<T> *pNode)
        {
            this->m_pCurrentNode = pNode;
            return *this;
        }

        Iterator &operator+(const unsigned offset)
        {
            for (unsigned idx = 0; idx < offset; ++idx)
            {
                if (this->m_pCurrentNode == nullptr)
                {
                    throw std::range_error("Access to an invalid object\n");
                }
                ++*this;
            }

            return *this;
        }

        Iterator &operator++()
        {
            if (this->m_pCurrentNode == nullptr)
            {
                throw std::range_error("Access to an invalid object\n");
            }
            this->m_pCurrentNode = this->m_pCurrentNode->next;

            return *this;
        }

        Iterator operator++(int)
        {
            if (this->m_pCurrentNode == nullptr)
            {
                throw std::range_error("Access to an invalid object\n");
            }
            auto iterator = *this;
            ++*this;

            return iterator;
        }

        bool operator!=(const Iterator &iterator)
        {
            return this->m_pCurrentNode != iterator.m_pCurrentNode;
        }

        T operator*()
        {
            return this->m_pCurrentNode->value;
        }

    private:
        const Node<T> *m_pCurrentNode;
    };

    Iterator begin() noexcept
    {
        return Iterator(first);
    }

    Iterator end() noexcept
    {
        return Iterator(last->next);
    }
};
