#include <iostream>
#include <memory>
#include <limits>
#include <optional>

const int DEFAULT_NODE_VALUE = std::numeric_limits<int>::lowest();

struct Node {
    int value;
    Node* prev;
    Node* next;
    
    Node() {
        this->value = DEFAULT_NODE_VALUE;
        resetLinks();
    }

    Node(const int value) : Node() {
        this->value = value;
    }

    void resetLinks() {
        prev = next = nullptr;
    }
};

class LinkedList {
private:
    bool isEmpty() const;
    int size;
    Node* first;
    Node* last;
public:
    LinkedList();
    LinkedList(const LinkedList&) = delete;
    ~LinkedList();

    void addLast(const int);
    void addFirst(const int);
    int indexOf(const int) const;
    bool contains(const int) const;
    int getSize() const {
        return size;
    }
    std::optional<Node> removeFirst();
    std::optional<Node> removeLast();
    std::optional<Node> remove(const int);
    std::unique_ptr<int[]> toArray() const;
    int getKthNodeFromTheEnd(const int) const;
    void reverse();
    void clear();

    friend std::ostream& operator<<(std::ostream&, const LinkedList&);
};

inline std::ostream& operator<<(std::ostream& os, const LinkedList& linkedList)
{
    for (auto current = linkedList.first; current != nullptr; current = current->next) {
        os << current->value << '\n';
    }

    return os;
}
