#pragma once

#include <iostream>
#include <exception>

#include "Stack.hpp"

void StackInSingleLinkedList::push(const int value)
{
    m_singleLinkedList.addLast(value);
}

void StackInSingleLinkedList::pop()
{
    const auto del_val = m_singleLinkedList.removeLast();
    (del_val == INVALID_NODE_VALUE) ? std::cout << "No value popped\n" : std::cout << "Value: " << del_val << " popped\n";
}

const int StackInSingleLinkedList::top() const
{
    if (m_singleLinkedList.isEmpty())
    {
        throw std::out_of_range("Empty stack");
    }
    const auto top_idx = m_singleLinkedList.getSize() - 1;
    const auto value = m_singleLinkedList.getAt(top_idx);

    return value;
}

void StackInSingleLinkedList::printStack(const bool toString) const
{
    (toString) ? std::cout << m_singleLinkedList.toString() << '\n' : std::cout << m_singleLinkedList << '\n';
}
