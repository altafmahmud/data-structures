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
    void printStack(const bool toString = false) const;
};
