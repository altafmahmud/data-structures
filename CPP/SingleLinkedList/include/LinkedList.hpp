#include <iostream>
#include <memory>
#include <limits>

constexpr int DEFAULT_NODE_VALUE = std::numeric_limits<int>::lowest();

struct Node
{
    int value;
    Node *next;

    Node()
    {
        value = DEFAULT_NODE_VALUE;
        next = nullptr;
    }

    Node(const int value) : Node()
    {
        this->value = value;
    }
};

class LinkedList
{
private:
    constexpr bool isEmpty() const noexcept
    {
        return size == 0;
    }
    int size;
    Node *first;
    Node *last;

public:
    LinkedList();
    LinkedList(const LinkedList &) = delete;
    ~LinkedList();

    bool addLast(const int);
    bool addFirst(const int);
    bool addAt(const int, const int);
    int indexOf(const int) const;
    bool contains(const int) const;
    constexpr int getSize() const noexcept
    {
        return size;
    }
    void removeFirst();
    void removeLast();
    std::unique_ptr<int[]> toArray() const;
    int getKthNodeFromTheEnd(const int) const;
    void reverse();
    void clear();

    friend std::ostream &operator<<(std::ostream &, const LinkedList &);
};

inline std::ostream &operator<<(std::ostream &os, const LinkedList &linkedList)
{
    for (auto current = linkedList.first; current != nullptr; current = current->next)
    {
        os << current->value << '\n';
    }

    return os;
}
