#include "SingleLinkedList.hpp"

class StackInSingleLinkedList
{
private:
    LinkedList m_singleLinkedList;

public:
    StackInSingleLinkedList() = default;
    StackInSingleLinkedList(const StackInSingleLinkedList &) = delete;
    ~StackInSingleLinkedList() = default;

    bool isEmpty() const noexcept
    {
        return m_singleLinkedList.isEmpty();
    }

    void push(const int);
    void pop();
    const int top() const;

    constexpr bool isEmpty() const noexcept
    {
        return m_singleLinkedList.getSize() != 0;
    }

    constexpr int getSize() const noexcept
    {
        return m_singleLinkedList.getSize();
    }

    void printStack(const bool toString = false) const;
};
