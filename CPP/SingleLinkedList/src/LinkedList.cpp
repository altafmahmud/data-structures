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
    node->next = nullptr;
    if (isEmpty()) {
        first = last = node;
    } else {
        last->next = node;
        last = node;
    }
    ++size;
}

void LinkedList::addFirst(const int value)
{
    Node* node = new Node(value);
    if (isEmpty()) {
        node->next = nullptr;
        first = last = node;
    } else {
        node->next = first;
        first = node;
    }
    ++size;
}

bool LinkedList::addAt(const int index, const int value) {
    if (index < 0) {
        std::cerr << "Invalid argument for index: " << index << '\n';
        return false;
    }
    if (index > size) {
        std::cerr << "Invalid argument for index: " << index << ", greater than size: " << size << '\n';
        return false;        
    }
    if (index == 0) {
        addFirst(value);
        return true;
    }
    if (index == size) {
        addLast(value);
        return true;
    }
    auto node = new Node(value);
    auto previous = first;
    auto current = first->next;
    unsigned idx = 1;
    while (idx < index && current != last) {
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
    const auto first_item = first->value;
    if (first == last) {
        delete first;
        first = last = nullptr;
        --size;
        std::cout << "First item: " << first_item << " deleted, the list empty\n";
        return;
    }
    auto second_item = first->next;
    first->next = nullptr;
    delete first;
    first = second_item;
    --size;
    std::cout << "First item: " << first_item << " deleted\n";
}

void LinkedList::removeLast()
{
    if (isEmpty()) {
        std::cout << "This list is empty, unable to remove the last item\n";
        return;
    }
    const auto last_item = last->value;
    if (first == last) {
        delete last;
        first = last = nullptr;
        --size;
        std::cout << "Last item: " << last_item << " deleted, the list empty\n";
        return;
    }
    auto previous = first;
    auto current = first->next;
    while (current != last) {
        previous = current;
        current = current->next;
    }
    delete current;
    last = previous;
    last->next = nullptr;
    --size;
    std::cout << "Last item: " << last_item << " deleted\n";
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
    auto previous = first;
    auto current = previous;
    for (auto diff = k-1; diff > 0 && current != nullptr; --diff) {
        current = current->next;
    }
    if (current == nullptr) {
        return -1;
    }
    while (current != last) {
        current = current->next;
        previous = previous->next;
    }
    return previous->value;
}

void LinkedList::reverse()
{
    if (isEmpty()) {
        return;
    }
    auto previous = first;
    auto current = previous->next;
    while (current != nullptr) {
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
    if (first != nullptr) {
        auto current = first;
        auto next = current->next;
        while (current != nullptr) {
            current->next = nullptr;
            delete current;
            current = nullptr;
            current = next;
            if (next != nullptr) {
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
