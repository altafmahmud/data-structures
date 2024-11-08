#include "SingleLinkedList.hpp"

class StackInSingleLinkedList
{
private:
    LinkedList m_singleLinkedList;

public:
    StackInSingleLinkedList() = default;
    StackInSingleLinkedList(const StackInSingleLinkedList &) = delete;
    ~StackInSingleLinkedList() = default;

    constexpr bool isEmpty() const noexcept
    {
        return m_singleLinkedList.isEmpty();
    }

    void push(const int);
    void pop();
    const int& top() const;

    constexpr int getSize() const noexcept
    {
        return m_singleLinkedList.getSize();
    }

    void printStack(const bool toString = false) const;
};
