#include <iostream>
#include <type_traits>
#include <iomanip>
#include <sstream>
#include <variant>

namespace
{
    constexpr unsigned PRECISION = 2;

    template <typename T>
    constexpr void setStreamPrecision(std::ostream &os)
    {
        if (std::is_same_v<T, float> || std::is_same_v<T, double>)
        {
            os << std::fixed << std::setprecision(PRECISION);
        }
    }
}

template <typename T>
struct Node
{
    T value;
    Node *prev;
    Node *next;

    constexpr Node() noexcept : value{}, prev(nullptr), next(nullptr) {}

    constexpr Node(const T &value) noexcept : value(value), prev(nullptr), next(nullptr) {}

    ~Node() noexcept
    {
        resetLinks();
    }

    constexpr void resetLinks() noexcept
    {
        prev = next = nullptr;
    }

    constexpr friend std::ostream &operator<<(std::ostream &os, const Node<T> &node)
    {
        setStreamPrecision<T>(os);
        os << node.value;
        return os;
    }
};

template <typename T>
class LinkedList
{
private:
    int deleteNode(Node<T> *node)
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
        delete node;

        return --size;
    }

    int size;
    Node<T> *first;
    Node<T> *last;

public:
    constexpr LinkedList() noexcept : size(0), first(nullptr), last(nullptr) {}

    constexpr LinkedList(const LinkedList &) = delete;

    LinkedList(LinkedList<T> &&rhs) : LinkedList()
    {
        for (auto itr = rhs.begin(); itr != rhs.end(); ++itr)
        {
            addLast(*itr);
        }
        rhs.clear();
    }

    ~LinkedList()
    {
        clear();
    }

    LinkedList<T> &operator=(LinkedList<T> &&rhs)
    {
        clear();
        for (auto itr = rhs.begin(); itr != rhs.end(); ++itr)
        {
            addLast(*itr);
        }
        rhs.clear();
        return *this;
    }

    int addLast(const T &value)
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
        return ++size;
    }

    int addFirst(const T &value)
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
        return ++size;
    }

    int addAt(const int index, const T &value)
    {
        if (index < 0)
        {
            std::stringstream ss;
            ss << "Invalid index: " << index << '\n';
            throw std::invalid_argument(ss.str());
        }
        else if (index > size)
        {
            std::stringstream ss;
            ss << "Invalid index: " << index << ", greater than list size: " << size << '\n';
            throw std::invalid_argument(ss.str());
        }
        if (index == 0)
        {
            return addFirst(value);
        }
        else if (index == size)
        {
            return addLast(value);
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
        }
        return ++size;
    }

    [[nodiscard]] int indexOf(const T &value) const
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

    [[nodiscard]] bool contains(const T &value) const
    {
        const auto index_of = indexOf(value);
        return (index_of >= 0);
    }

    [[nodiscard]] constexpr int getSize() const noexcept
    {
        return size;
    }

    [[nodiscard]] constexpr bool isEmpty() const noexcept
    {
        return size == 0;
    }

    int removeFirst()
    {
        if (isEmpty())
        {
            throw std::runtime_error("This list is empty, unable to remove the first item\n");
        }
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
        return --size;
    }

    int removeLast()
    {
        if (isEmpty())
        {
            throw std::runtime_error("This list is empty, unable to remove the last item\n");
        }
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
        return --size;
    }

    int remove(const T &value)
    {
        if (isEmpty())
        {
            std::stringstream ss;
            ss << "This list is empty, unable to remove node: " << value << '\n';
            throw std::runtime_error(ss.str());
        }
        if (first->value == value)
        {
            return removeFirst();
        }
        auto current = first;
        while (current != nullptr && current->value != value)
        {
            current = current->next;
        }
        if (current == last)
        {
            return removeLast();
        }
        if (current == nullptr)
        {
            std::stringstream ss;
            ss << "Unable to remove value: " << value << ", not found\n";
            throw std::runtime_error(ss.str());
        }
        auto current_size = 0;
        try
        {
            current_size = deleteNode(current);
        }
        catch (const std::exception &e)
        {
            throw;
        }
        return current_size;
    }

    int removeAt(const int index)
    {
        if (isEmpty())
        {
            std::stringstream ss;
            ss << "This list is empty, unable to remove node at position: " << index << '\n';
            throw std::runtime_error(ss.str());
        }
        if (index >= size || index < 0)
        {
            std::stringstream ss;
            ss << "The index out of range: " << index << ", size of the list: " << size << '\n';
            throw std::runtime_error(ss.str());
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
        auto current_size = 0;
        try
        {
            current_size = deleteNode(current);
        }
        catch (const std::exception &e)
        {
            throw;
        }
        return current_size;
    }

    [[nodiscard]] std::unique_ptr<T[]> toArray() const
    {
        std::unique_ptr<T[]> int_arr = std::make_unique<T[]>(size);
        unsigned idx = 0;
        for (auto current = first; current != nullptr; current = current->next)
        {
            int_arr[idx++] = current->value;
        }
        return int_arr;
    }

    [[nodiscard]] const T &getKthNodeFromTheEnd(const int k) const
    {
        if (k < 1 || k > size)
        {
            std::stringstream ss;
            ss << "Invalid argument: " << std::to_string(k) << " to get an item, argument must be in: [" << 1 << '-' << size << "]\n";
            throw std::runtime_error(ss.str());
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

    [[nodiscard]] const T &at(const int index) const
    {
        if (index < 0 || index >= size)
        {
            std::stringstream ss;
            ss << "Invalid argument: " << index << " to get an item, argument must be in: [" << 0 << '-' << size - 1 << "]\n";
            throw std::runtime_error(ss.str());
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
            std::stringstream ss;
            ss << "Passed the list while searching for the index: " << index << '\n';
            throw std::runtime_error(ss.str());
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

    [[nodiscard]] const std::string toString() const
    {
        std::ostringstream oss;
        setStreamPrecision<T>(oss);
        oss << "[";
        for (auto node = first; node != nullptr; node = node->next)
        {
            oss << node->value;
            if (node->next != nullptr)
            {
                oss << ", ";
            }
        }
        oss << "]";
        return oss.str();
    }

    int clear()
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
            first = last = nullptr;
        }
        return size;
    }

    friend std::ostream &operator<<(std::ostream &os, const LinkedList<T> &linkedList)
    {
        for (auto current = linkedList.first; current != nullptr; current = current->next)
        {
            os << *current << '\n';
        }
        return os;
    }

    class Iterator
    {
    public:
        constexpr Iterator() noexcept : m_pLinkedList(nullptr), m_pCurrentNode(nullptr) {}

        constexpr Iterator(LinkedList<T> *pLinkedList, Node<T> *pNode) noexcept : m_pLinkedList(pLinkedList), m_pCurrentNode(pNode) {}

        ~Iterator() = default;

        constexpr Iterator &operator=(const Iterator &itr) noexcept
        {
            m_pLinkedList = itr.m_pLinkedList;
            m_pCurrentNode = itr.m_pCurrentNode;
            return *this;
        }

        Iterator &operator+(const int offset)
        {
            if (offset < 0)
            {
                std::stringstream ss;
                ss << "Invalid offset: " << offset << '\n';
                throw std::range_error(ss.str());
            }
            for (unsigned idx = 0; idx < offset; ++idx)
            {
                if (m_pCurrentNode == nullptr)
                {
                    throw std::range_error("Access to an invalid object\n");
                }
                ++*this;
            }
            return *this;
        }

        Iterator &operator-(const int offset)
        {
            if (offset < 0)
            {
                std::stringstream ss;
                ss << "Invalid offset: " << offset << '\n';
                throw std::range_error(ss.str());
            }
            if (m_pLinkedList == nullptr)
            {
                throw std::bad_variant_access();
            }
            int idx = offset;
            if (m_pCurrentNode == nullptr)
            {
                m_pCurrentNode = m_pLinkedList->last;
                --idx;
            }
            while (idx > 0)
            {
                if (m_pCurrentNode == nullptr)
                {
                    throw std::range_error("Access to an invalid object\n");
                }
                --*this;
                --idx;
            }
            return *this;
        }

        Iterator &operator++()
        {
            if (m_pCurrentNode == nullptr)
            {
                throw std::range_error("Access to an invalid object\n");
            }
            m_pCurrentNode = m_pCurrentNode->next;
            return *this;
        }

        Iterator &operator--()
        {
            if (m_pLinkedList == nullptr)
            {
                throw std::bad_variant_access();
            }
            if (m_pCurrentNode == nullptr)
            {
                m_pCurrentNode = m_pLinkedList->last;
                return *this;
            }
            m_pCurrentNode = m_pCurrentNode->prev;
            return *this;
        }

        Iterator operator++(int)
        {
            if (m_pCurrentNode == nullptr)
            {
                throw std::range_error("Access to an invalid object\n");
            }
            auto iterator = *this;
            ++*this;
            return iterator;
        }

        Iterator operator--(int)
        {
            if (m_pLinkedList == nullptr)
            {
                throw std::bad_variant_access();
            }
            auto iterator = *this;
            if (m_pCurrentNode == nullptr)
            {
                m_pCurrentNode = m_pLinkedList->last;
                return iterator;
            }
            --*this;
            return iterator;
        }

        constexpr bool &operator==(const Iterator &iterator) const noexcept
        {
            return m_pCurrentNode == iterator.m_pCurrentNode;
        }

        constexpr bool operator==(const Node<T> *pNode) const noexcept
        {
            return m_pCurrentNode == pNode;
        }

        constexpr bool operator!=(const Iterator &iterator) const noexcept
        {
            return m_pCurrentNode != iterator.m_pCurrentNode;
        }

        constexpr bool operator!=(const Node<T> *pNode) const noexcept
        {
            return m_pCurrentNode != pNode;
        }

        constexpr T &operator*()
        {
            if (m_pCurrentNode == nullptr)
            {
                throw std::bad_variant_access();
            }
            return m_pCurrentNode->value;
        }

    private:
        Node<T> *m_pCurrentNode;
        LinkedList<T> *m_pLinkedList;
    };

    constexpr Iterator begin() noexcept
    {
        return Iterator(this, first);
    }

    constexpr Iterator end() noexcept
    {
        return Iterator(this, last->next);
    }
};
