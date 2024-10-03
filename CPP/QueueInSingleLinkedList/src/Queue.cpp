#pragma once

#include <iostream>
#include <exception>

#include "Queue.hpp"

void QueueInSingleLinkedList::enqueue(const int value)
{
    m_singleLinkedList.addLast(value);
}

void QueueInSingleLinkedList::dequeue()
{
    const auto del_val = m_singleLinkedList.removeLast();
    (del_val == INVALID_NODE_VALUE) ? std::cout << "No value popped\n" : std::cout << "Value: " << del_val << " popped\n";
}

const int& QueueInSingleLinkedList::peek() const
{
    if (m_singleLinkedList.isEmpty())
    {
        throw std::out_of_range("Empty stack");
    }
    const auto top_idx = m_singleLinkedList.getSize() - 1;
    const auto& opt_node = m_singleLinkedList.getAt(top_idx);
    if (!opt_node.has_value())
    {
        throw std::runtime_error("No item found!");
    }
    const auto& node = opt_node.value();

    return node.value;
}

void QueueInSingleLinkedList::printQueue(const bool toString) const
{
    (toString) ? std::cout << m_singleLinkedList.toString() << '\n' : std::cout << m_singleLinkedList << '\n';
}
