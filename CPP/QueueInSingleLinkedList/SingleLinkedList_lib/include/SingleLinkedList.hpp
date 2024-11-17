#include <iostream>
#include <memory>
#include <type_traits>
#include <iomanip>
#include <sstream>

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
    Node<T> *next;

    constexpr Node() noexcept
    {
        value = {};
        next = nullptr;
    }

    constexpr Node(const T &val) noexcept : value(val), next(nullptr) {}

    constexpr Node(const Node<T> &) = delete;

    ~Node() noexcept
    {
        next = nullptr;
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
public:
    constexpr LinkedList() noexcept : size(0), first(nullptr), last(nullptr) {}

    constexpr LinkedList(const LinkedList<T> &) = delete;

    LinkedList(LinkedList<T> &&rhs) : LinkedList()
    {
        for (auto itr = rhs.begin(); itr != rhs.end(); ++itr)
        {
            addLast(*itr);
        }
        rhs.clear();
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

    ~LinkedList()
    {
        clear();
    }

    int addLast(const T &value)
    {
        auto node = new Node<T>(value);
        if (isEmpty())
        {
            first = last = node;
        }
        else
        {
            last->next = node;
            last = node;
        }
        return ++size;
    }

    int addFirst(const T &value)
    {
        auto node = new Node<T>(value);
        if (isEmpty())
        {
            node->next = nullptr;
            first = last = node;
        }
        else
        {
            node->next = first;
            first = node;
        }
        return ++size;
    }

    int addAt(const int index, const T &value)
    {
        if (index < 0)
        {
            throw std::invalid_argument("Invalid argument for index: " + std::to_string(index) + "\n");
        }
        if (index > size)
        {
            throw std::invalid_argument("Invalid argument for index: " + std::to_string(index) + ", greater than size: " + std::to_string(size) + "\n");
        }
        if (index == 0)
        {
            return addFirst(value);
        }
        if (index == size)
        {
            return addLast(value);
        }
        auto node = new Node<T>(value);
        auto previous = first;
        auto current = first->next;
        unsigned idx = 1;
        while (idx < index && current != last)
        {
            previous = current;
            current = current->next;
            ++idx;
        }
        node->next = current;
        previous->next = node;

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
            first->next = nullptr;
            delete first;
            first = last = nullptr;
            return --size;
        }
        auto second_item = first->next;
        first->next = nullptr;
        delete first;
        first = second_item;

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
            delete last;
            first = last = nullptr;
            return --size;
        }
        auto previous = first;
        auto current = first->next;
        while (current != last)
        {
            previous = current;
            current = current->next;
        }
        current->next = nullptr;
        delete current;
        last = previous;
        last->next = nullptr;

        return --size;
    }

    int removeAt(const int index)
    {
        if (isEmpty())
        {
            throw std::runtime_error("This list is empty, unable to remove the item at position: " + std::to_string(index) + '\n');
        }
        if (index < 0)
        {
            throw std::runtime_error("Invalid index: " + std::to_string(index) + " to remove item\n");
        }
        if (index >= size)
        {
            throw std::runtime_error("Invalid index: " + std::to_string(index) + " to remove item, index must be in: [" + std::to_string(0) + '-' + std::to_string(size - 1) + "]\n");
        }

        if (index == 0)
        {
            return removeFirst();
        }
        if (index == size - 1)
        {
            return removeLast();
        }
        unsigned idx = 1;
        auto previous = first;
        auto current = first->next;
        while (current != last && idx < index)
        {
            previous = current;
            current = current->next;
            ++idx;
        }
        auto next = current->next;
        current->next = nullptr;
        delete current;
        previous->next = next;

        return --size;
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

    [[nodiscard]] const T &at(const int index) const
    {
        if (isEmpty())
        {
            throw std::runtime_error("This list is empty, unable to get the item at position: " + std::to_string(index) + '\n');
        }
        if (index < 0 || index >= size)
        {
            throw std::runtime_error("Invalid index: " + std::to_string(index) + " to get an item, index must be in: [" + std::to_string(0) + '-' + std::to_string(size - 1) + "]\n");
        }

        if (index == 0)
        {
            return first->value;
        }
        if (index == size - 1)
        {
            return last->value;
        }
        unsigned idx = 1;
        auto current = first->next;
        while (idx < index && current != last)
        {
            current = current->next;
            ++idx;
        }
        return current->value;
    }

    [[nodiscard]] T &getKthNodeFromTheEnd(const int k)
    {
        if (k < 1)
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
        auto previous = first;
        auto current = previous;
        for (auto diff = k - 1; diff > 0 && current != nullptr; --diff)
        {
            current = current->next;
        }
        if (current == nullptr)
        {
            throw std::runtime_error("Reached at the end of the list while setting the difference!");
        }
        while (current != last)
        {
            current = current->next;
            previous = previous->next;
        }

        return previous->value;
    }

    void reverse()
    {
        if (isEmpty())
        {
            return;
        }
        auto previous = first;
        auto current = previous->next;
        while (current != nullptr)
        {
            auto next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        last = first;
        first = previous;
        last->next = nullptr;
    }

    int clear()
    {
        unsigned count = 0;
        if (first != nullptr)
        {
            auto current = first;
            auto next = current->next;
            while (current != nullptr)
            {
                current->next = nullptr;
                delete current;
                current = nullptr;
                current = next;
                if (current != nullptr)
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
        constexpr Iterator() noexcept : m_pCurrentNode(nullptr) {}

        constexpr Iterator(Node<T> *pNode) noexcept : m_pCurrentNode(pNode) {}

        constexpr Iterator &operator=(Node<T> *pNode)
        {
            m_pCurrentNode = pNode;
            return *this;
        }

        Iterator &operator+(const int offset)
        {
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

        Iterator &operator++()
        {
            if (m_pCurrentNode == nullptr)
            {
                throw std::range_error("Access to an invalid object\n");
            }
            m_pCurrentNode = m_pCurrentNode->next;

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

        constexpr bool operator!=(const Iterator &iterator) const
        {
            return m_pCurrentNode != iterator.m_pCurrentNode;
        }

        constexpr T &operator*()
        {
            return m_pCurrentNode->value;
        }

    private:
        Node<T> *m_pCurrentNode;
    };

    constexpr Iterator begin() noexcept
    {
        return Iterator(first);
    }

    constexpr Iterator end() noexcept
    {
        return Iterator(last->next);
    }

private:
    int size;
    Node<T> *first;
    Node<T> *last;
};
