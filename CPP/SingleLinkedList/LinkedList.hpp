#include <iostream>

struct Node {
    int value;
    Node* next;
    Node(const int value) {
        this->value = value;
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
    void removeFirst();
    void removeLast();
    int* toArray() const;
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
