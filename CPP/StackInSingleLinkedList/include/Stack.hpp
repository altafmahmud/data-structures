#include "SingleLinkedList.hpp"

class StackInSingleLinkedList {
private:
    LinkedList m_singleLinkedList;

public:
    StackInSingleLinkedList() = default;
    StackInSingleLinkedList(const StackInSingleLinkedList&) = delete;
    ~StackInSingleLinkedList() = default;

    void push(const int);
    void pop();
    
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
