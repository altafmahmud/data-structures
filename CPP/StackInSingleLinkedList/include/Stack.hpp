#include "SingleLinkedList.hpp"

template <typename T>
class StackInSingleLinkedList
{
private:
    LinkedList<T> m_singleLinkedList;

public:
    constexpr StackInSingleLinkedList() noexcept = default;

    constexpr StackInSingleLinkedList(const StackInSingleLinkedList &) = delete;

    StackInSingleLinkedList(StackInSingleLinkedList<T> &&rhs) : StackInSingleLinkedList()
    {
        m_singleLinkedList = std::move(rhs.m_singleLinkedList);
    }

    ~StackInSingleLinkedList() = default;

    StackInSingleLinkedList<T> &operator=(StackInSingleLinkedList<T> &&rhs)
    {
        clear();
        m_singleLinkedList = std::move(rhs.m_singleLinkedList);
        return *this;
    }

    [[nodiscard]] constexpr bool isEmpty() const noexcept
    {
        return m_singleLinkedList.isEmpty();
    }

    void push(const T &value)
    {
        m_singleLinkedList.addLast(value);
    }

    void pop()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Empty stack, failed to pop()\n");
        }
        m_singleLinkedList.removeLast();
    }

    [[nodiscard]] const T &top() const
    {
        if (m_singleLinkedList.isEmpty())
        {
            throw std::out_of_range("Empty stack");
        }
        const auto top_idx = m_singleLinkedList.getSize() - 1;
        const auto &value = m_singleLinkedList.at(top_idx);
        return value;
    }

    [[nodiscard]] constexpr int getSize() const noexcept
    {
        return m_singleLinkedList.getSize();
    }

    void printStack(const bool toString = false) const
    {
        (toString) ? std::cout << m_singleLinkedList.toString() << '\n' : std::cout << m_singleLinkedList << '\n';
    }

    int clear()
    {
        return m_singleLinkedList.clear();
    }
};
