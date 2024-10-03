#pragma once

#include <iostream>

#include "Stack.hpp"

void StackInSingleLinkedList::push(const int value)
{
    m_singleLinkedList.addLast(value);
}

void StackInSingleLinkedList::pop()
{
    const auto opt_val = m_singleLinkedList.removeLast();
    (!opt_val.has_value()) ? std::cout << "No value popped\n" : std::cout << "Value: " << opt_val.value().value << " popped\n";
}

void StackInSingleLinkedList::printStack(const bool toString) const
{
    (toString) ? std::cout << m_singleLinkedList.toString() : std::cout << m_singleLinkedList;
}
