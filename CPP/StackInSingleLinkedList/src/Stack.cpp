#pragma once

#include <iostream>

#include "Stack.hpp"

void StackInSingleLinkedList::push(const int value)
{
    m_singleLinkedList.addLast(value);
}

void StackInSingleLinkedList::pop()
{
    m_singleLinkedList.removeLast();
}

void StackInSingleLinkedList::printStack() const
{
    std::cout << m_singleLinkedList;
}
