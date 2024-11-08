#pragma once

#include "LinkedList.hpp"

#include <variant>

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
    return (size == 0);
}

void LinkedList::addLast(const int value)
{
    Node* node = new Node(value);
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
    if (isEmpty()) {
        first = last = node;
    } else {
        node->next = first;
        first->prev = node;
        first = node;
    }
    ++size;
}

void LinkedList::add(const int index, const int value)
{
    if (index < 0) {
        throw std::invalid_argument("Invalid index: " + std::to_string(index));
    }
    else if (index > size) {
        throw std::invalid_argument("Invalid index: " + std::to_string(index) + ", greater than list size: " + std::to_string(size));
    }
    if (index == 0) {
        addFirst(value);
    }
    else if (index == size) {
        addLast(value);
    }
    else {
        Node *node = new Node(value);
        unsigned idx = 0;
        auto current = first;
        while (current != nullptr && idx < index) {
            current = current->next;
            ++idx;
        }
        if (current == nullptr) {
            delete node;
            throw std::bad_variant_access();
        }
        auto previous = current->prev;
        previous->next = node;
        current->prev = node;
        node->prev = previous;
        node->next = current;
        ++size;
    }
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

std::optional<Node> LinkedList::removeFirst()
{
    if (isEmpty()) {
        std::cout << "This list is empty, unable to remove the first item\n";
        return std::nullopt;
    }
    const auto first_value = first->value;
    Node node;
    if (first == last) {
        first->resetLinks();
        node = *first;
        delete first;
        first = last = nullptr;
        std::cout << "First item: " << first_value << " deleted, the list become empty\n";
    } else {
        auto second_node = first->next;
        second_node->prev = nullptr;
        first->resetLinks();
        node = *first;
        delete first;
        first = second_node;
        std::cout << "First item: " << first_value << " deleted\n";
    }
    --size;
    return std::make_optional<Node>(node);
}

std::optional<Node> LinkedList::removeLast()
{
    if (isEmpty()) {
        std::cout << "This list is empty, unable to remove the last item\n";
        return std::nullopt;
    }
    const auto last_value = last->value;
    Node node;
    if (first == last) {
        last->resetLinks();
        node = *last;
        delete last;
        first = last = nullptr;
        std::cout << "Last item: " << last_value << " deleted, the list become empty\n";
    } else {
        auto previous = last->prev;
        previous->next = nullptr;
        last->resetLinks();
        node = *last;
        delete last;
        last = previous;
        std::cout << "Last item: " << last_value << " deleted\n";
    }
    --size;
    return std::make_optional<Node>(node);
}

std::optional<Node> LinkedList::remove(const int value) {
    if (isEmpty()) {
        std::cout << "This list is empty, unable to remove node: " << value << '\n';
        return std::nullopt;
    }
    if (first->value == value) {
        return removeFirst();
    }
    auto current = first;
    while (current != nullptr && current->value != value) {
        current = current->next;
    }
    if (current == last) {
        return removeLast();
    }
    if (current != nullptr) {
        auto previous = current->prev;
        auto next = current->next;
        previous->next = next;
        next->prev = previous;
        current->resetLinks();
        auto node = *current;
        delete current;
        --size;
        std::cout << "Node: " << node.value << " deleted\n";
        return std::make_optional<Node>(node);
    }
    return std::nullopt;
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
