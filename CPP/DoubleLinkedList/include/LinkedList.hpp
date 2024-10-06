#include <iostream>
#include <memory>
#include <limits>

constexpr int INVALID_NODE_VALUE = std::numeric_limits<int>::lowest();

struct Node
{
    int value;
    Node *prev;
    Node *next;

    Node()
    {
        this->value = INVALID_NODE_VALUE;
        resetLinks();
    }

    Node(const int value) : Node()
    {
        this->value = value;
    }

    constexpr void resetLinks()
    {
        prev = next = nullptr;
    }
};

class LinkedList
{
private:
    int deleteNode(Node *);
    int size;
    Node *first;
    Node *last;

public:
    LinkedList() noexcept;
    LinkedList(const LinkedList &) = delete;
    ~LinkedList();

    void addLast(const int);
    void addFirst(const int);
    void addAt(const int, const int);
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
    int remove(const int);
    int removeAt(const int);
    std::unique_ptr<int[]> toArray() const;
    int &getKthNodeFromTheEnd(const int) const;
    int &getAt(const int) const;
    void reverse();
    const std::string toString() const;
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
};

inline std::ostream &operator<<(std::ostream &os, const LinkedList &linkedList)
{
    for (auto current = linkedList.first; current != nullptr; current = current->next)
    {
        os << current->value << '\n';
    }

    return os;
}
