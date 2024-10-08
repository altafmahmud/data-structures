#include <iostream>
#include <memory>
#include <limits>

constexpr int INVALID_NODE_VALUE = std::numeric_limits<int>::lowest();

struct Node
{
    int value;
    Node *next;

    Node()
    {
        value = INVALID_NODE_VALUE;
        next = nullptr;
    }

    Node(const int value) : Node()
    {
        this->value = value;
    }
};

class LinkedList
{
public:
    LinkedList() noexcept;
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
    constexpr bool isEmpty() const noexcept
    {
        return size == 0;
    }
    int removeFirst();
    int removeLast();
    int removeAt(const int);
    std::unique_ptr<int[]> toArray() const;
    const std::string toString() const;
    int &getAt(const int) const;
    int &getKthNodeFromTheEnd(const int) const;
    void reverse();
    void clear();

    friend std::ostream &operator<<(std::ostream &, const LinkedList &);

    class Iterator
    {
    public:
        Iterator() noexcept;
        Iterator(const Node*) noexcept;

        Iterator& operator=(const Node*);
        Iterator& operator+(const unsigned);
        Iterator& operator++();
        Iterator operator++(int);
        bool operator!=(const Iterator&);
        int operator*();

    private:
        const Node* m_pCurrentNode;
    };

    Iterator begin() noexcept
    {
        return Iterator(first);
    }

    Iterator end() noexcept
    {
        return Iterator(last->next);
    }

private:
    int size;
    Node *first;
    Node *last;    
};

inline std::ostream &operator<<(std::ostream &os, const LinkedList &linkedList)
{
    for (auto current = linkedList.first; current != nullptr; current = current->next)
    {
        os << current->value << '\n';
    }

    return os;
}
