#pragma once

#include "LinkedList.hpp"

LinkedList::LinkedList() : size(0)
{
    first = last = nullptr;
}

LinkedList::~LinkedList()
{
    clear();
}

bool LinkedList::addLast(const int value)
{
    if (value == INVALID_NODE_VALUE)
    {
        std::cerr << "Invalid value to be added: " << value << '\n';
        return false;
    }
    Node *node = new Node(value);
    node->next = nullptr;
    if (isEmpty())
    {
        first = last = node;
    }
    else
    {
        last->next = node;
        last = node;
    }
    ++size;

    return true;
}

bool LinkedList::addFirst(const int value)
{
    if (value == INVALID_NODE_VALUE)
    {
        std::cerr << "Invalid value to be added: " << value << '\n';
        return false;
    }
    Node *node = new Node(value);
    if (isEmpty())
    {
        node->next = nullptr;
        first = last = node;
    }
    else
    {
        node->next = first;
        first = node;
    }
    ++size;

    return true;
}

bool LinkedList::addAt(const int index, const int value)
{
    if (index < 0)
    {
        std::cerr << "Invalid argument for index: " << index << '\n';
        return false;
    }
    if (index > size)
    {
        std::cerr << "Invalid argument for index: " << index << ", greater than size: " << size << '\n';
        return false;
    }
    if (index == 0)
    {
        return addFirst(value);
    }
    if (index == size)
    {
        return addLast(value);
    }
    auto node = new Node(value);
    auto previous = first;
    auto current = first->next;
    unsigned idx = 1;
    while (idx < index && current != last)
    {
        previous = current;
        current = current->next;
        ++idx;
    }
    node->next = current;
    previous->next = node;
    ++size;
    std::cout << "Node: " << value << " added at position: " << index << '\n';

    return true;
}

int LinkedList::indexOf(const int value) const
{
    unsigned index = 0;
    auto current = first;
    while (current != nullptr && current->value != value)
    {
        current = current->next;
        ++index;
    }
    return (current != nullptr) ? index : -1;
}

bool LinkedList::contains(const int value) const
{
    const auto index_of = indexOf(value);
    return (index_of >= 0);
}

int LinkedList::removeFirst()
{
    if (isEmpty())
    {
        std::cout << "This list is empty, unable to remove the first item\n";
        return INVALID_NODE_VALUE;
    }
    if (first == last)
    {
        first->next = nullptr;
        const auto del_val = first->value;
        delete first;
        first = last = nullptr;
        --size;
        std::cout << "First item: " << del_val << " deleted, the list becomes empty\n";
        return del_val;
    }
    auto second_item = first->next;
    first->next = nullptr;
    const auto del_val = first->value;
    delete first;
    first = second_item;
    --size;
    std::cout << "First item: " << del_val << " deleted\n";

    return del_val;
}

int LinkedList::removeLast()
{
    if (isEmpty())
    {
        std::cout << "This list is empty, unable to remove the last item\n";
        return INVALID_NODE_VALUE;
    }
    if (first == last)
    {
        const auto del_val = last->value;
        delete last;
        first = last = nullptr;
        --size;
        std::cout << "Last item: " << del_val << " deleted, the list becomes empty\n";
        return del_val;
    }
    auto previous = first;
    auto current = first->next;
    while (current != last)
    {
        previous = current;
        current = current->next;
    }
    current->next = nullptr;
    const auto del_val = current->value;
    delete current;
    last = previous;
    last->next = nullptr;
    --size;
    std::cout << "Last item: " << del_val << " deleted\n";

    return del_val;
}

int LinkedList::removeAt(const int index)
{
    if (isEmpty())
    {
        std::cout << "This list is empty, unable to remove the item at position: " << index << '\n';
        return INVALID_NODE_VALUE;
    }
    if (index < 0)
    {
        std::cerr << "Invalid index: " << index << " to remove item\n";
        return INVALID_NODE_VALUE;
    }
    if (index >= size)
    {
        std::cerr << "Invalid index: " << index << " to remove item, index must be in: [" << 0 << '-' << size-1 << "]\n";
        return INVALID_NODE_VALUE;
    }

    if (index == 0)
    {
        return removeFirst();
    }
    if (index == size-1)
    {
        return removeLast();
    }
    unsigned idx = 1;
    auto previous = first;
    auto current = first->next;
    while (current != last && idx < index)
    {
        previous = current;
        current = current->next;
        ++idx;
    }
    auto next = current->next;
    current->next = nullptr;
    const auto del_val = current->value;
    delete current;
    previous->next = next;
    --size;
    std::cout << "Item: " << del_val << " at position: " << index << " deleted\n";

    return del_val;
}

std::unique_ptr<int[]> LinkedList::toArray() const
{
    std::unique_ptr<int[]> int_arr = std::make_unique<int[]>(size);
    unsigned idx = 0;
    for (auto current = first; current != nullptr; current = current->next)
    {
        int_arr[idx++] = current->value;
    }
    return int_arr;
}

const std::string LinkedList::toString() const
{
    std::string list_str("[");
    for (auto node = first; node != nullptr; node = node->next)
    {
        list_str += std::to_string(node->value);
        if (node->next != nullptr)
        {
            list_str += ", ";
        }
    }
    list_str += "]";

    return list_str;
}

int LinkedList::getKthNodeFromTheEnd(const int k) const
{
    if (k < 1 || isEmpty())
    {
        return -1;
    }
    if (k == 1)
    {
        return last->value;
    }
    auto previous = first;
    auto current = previous;
    for (auto diff = k - 1; diff > 0 && current != nullptr; --diff)
    {
        current = current->next;
    }
    if (current == nullptr)
    {
        return -1;
    }
    while (current != last)
    {
        current = current->next;
        previous = previous->next;
    }

    return previous->value;
}

void LinkedList::reverse()
{
    if (isEmpty())
    {
        return;
    }
    auto previous = first;
    auto current = previous->next;
    while (current != nullptr)
    {
        auto next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    last = first;
    first = previous;
    last->next = nullptr;
}

void LinkedList::clear()
{
    unsigned count = 0;
    if (first != nullptr)
    {
        auto current = first;
        auto next = current->next;
        while (current != nullptr)
        {
            current->next = nullptr;
            delete current;
            current = nullptr;
            current = next;
            if (next != nullptr)
            {
                next = current->next;
            }
            ++count;
        }
        std::cout << count << " nodes deleted\n";
        size -= count;
        first = last = nullptr;
        std::cout << "The size of the list: " << getSize() << '\n';
    }
}
