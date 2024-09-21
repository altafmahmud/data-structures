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

bool LinkedList::isEmpty() const
{
    return (first == nullptr && last == nullptr);
}

void LinkedList::addLast(const int value)
{
    Node* node = new Node(value);
    node->prev = node->next = nullptr;
    if (isEmpty()) {
        first = last = node;
    } else {
        last->next = node;
        node->prev = last;
        last = node;
    }
    ++size;
}

void LinkedList::addFirst(const int value)
{
    Node* node = new Node(value);
    node->prev = node->next = nullptr;
    if (isEmpty()) {
        first = last = node;
    } else {
        node->next = first;
        first->prev = node;
        first = node;
    }
    ++size;
}

int LinkedList::indexOf(const int value) const
{
    unsigned index = 0;
    auto current = first;
    while (current != nullptr && current->value != value) {
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

void LinkedList::removeFirst()
{
    if (isEmpty()) {
        std::cout << "This list is empty, unable to remove the first item\n";
        return;
    }
    const auto first_value = first->value;
    if (first == last) {
        delete first;
        first = last = nullptr;
        --size;
        std::cout << "First item: " << first_value << " deleted, the list empty\n";
        return;
    }
    auto second_node = first->next;
    first->next = second_node->prev = nullptr;
    delete first;
    first = second_node;
    --size;
    std::cout << "First item: " << first_value << " deleted\n";
}

void LinkedList::removeLast()
{
    if (isEmpty()) {
        std::cout << "This list is empty, unable to remove the last item\n";
        return;
    }
    const auto last_value = last->value;
    if (first == last) {
        delete last;
        first = last = nullptr;
        --size;
        std::cout << "Last item: " << last_value << " deleted, the list empty\n";
        return;
    }
    auto previous = last->prev;
    previous->next = last->prev = nullptr;
    delete last;
    last = previous;
    --size;
    std::cout << "Last item: " << last_value << " deleted\n";
}

std::unique_ptr<int[]> LinkedList::toArray() const
{
    std::unique_ptr<int[]> int_arr = std::make_unique<int[]>(size);
    unsigned idx = 0;
    for (auto current = first; current != nullptr; current = current->next) {
        int_arr[idx++] = current->value;
    }
    return int_arr;
}

int LinkedList::getKthNodeFromTheEnd(const int k) const
{
    if (k < 1 || isEmpty()) {
        return -1;
    }
    if (k == 1) {
        return last->value;
    }
    auto current = last;
    for (auto diff = k-1; diff >= 1 && current != nullptr; --diff) {
        current = current->prev;
    }
    if (current == nullptr) {
        return -1;
    }

    return current->value;
}

void LinkedList::reverse()
{
    if (isEmpty() || first == last) {
        return;
    }
    auto current = last;
    auto previous = current->prev;
    while (current != nullptr) {
        current->prev = current->next;
        current->next = previous;
        current = previous;
        if (previous != nullptr) {
            previous = previous->prev;
        }
    }
    current = first;
    first = last;
    last = current;
}

void LinkedList::clear()
{
    unsigned count = 0;
    if (!isEmpty()) {
        auto current = first;
        auto next = current->next;
        while (current != nullptr) {
            current->prev = current->next = nullptr;
            delete current;
            current = next;
            if (next != nullptr) {
                next = current->next;
            }
            ++count;
        }
        size -= count;
        std::cout << count << " nodes deleted, size of the list: " << size << '\n';
        first = last = nullptr;
    }
}
