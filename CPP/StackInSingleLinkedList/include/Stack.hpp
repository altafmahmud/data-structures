#include "SingleLinkedList.hpp"

class StackInSingleLinkedList {
private:
    SingleLinkedList m_singleLinkedList;

public:
    StackInSingleLinkedList() = default;
    StackInSingleLinkedList(const StackInSingleLinkedList&) = delete;
    ~StackInSingleLinkedList() = default;

    void push(const int);
    void pop();
    void printStack() const;
};

