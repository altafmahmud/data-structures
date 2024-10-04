#pragma once

#include <iostream>
#include <exception>

#include "Queue.hpp"

void QueueInSingleLinkedList::enqueue(const int value)
{
    if (m_singleLinkedList.addLast(value))
    {
        std::cout << "Enqueued: " << value << '\n';
    }
}

void QueueInSingleLinkedList::dequeue()
{
    if (isEmpty())
    {
        throw std::out_of_range("Empty queue");
    }
    m_singleLinkedList.removeFirst();
}

const int &QueueInSingleLinkedList::peek() const
{
    if (isEmpty())
    {
        throw std::out_of_range("Empty queue");
    }
    const auto &value = m_singleLinkedList.getAt(0);

    return value;
}

void QueueInSingleLinkedList::printQueue(const bool toString) const
{
    (toString) ? std::cout << m_singleLinkedList.toString() << '\n' : std::cout << m_singleLinkedList << '\n';
}
