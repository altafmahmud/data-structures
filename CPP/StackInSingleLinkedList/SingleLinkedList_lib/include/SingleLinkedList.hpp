#include <iostream>
#include <memory>

struct Node {
    int value;
    Node* next;
    Node(const int value) {
        this->value = value;
    }
};

class SingleLinkedList {
private:
    bool isEmpty() const;
    int size;
    Node* first;
    Node* last;

public:
    SingleLinkedList();
    SingleLinkedList(const SingleLinkedList&) = delete;
    ~SingleLinkedList();

    void addLast(const int);
    void addFirst(const int);
    int indexOf(const int) const;
    bool contains(const int) const;
    int getSize() const {
        return size;
    }
    void removeFirst();
    void removeLast();
    std::unique_ptr<int[]> toArray() const;
    int getKthNodeFromTheEnd(const int) const;
    void reverse();
    void clear();

    friend std::ostream& operator<<(std::ostream&, const SingleLinkedList&);
};

inline std::ostream& operator<<(std::ostream& os, const SingleLinkedList& singleLinkedList)
{
    for (auto current = singleLinkedList.first; current != nullptr; current = current->next) {
        os << current->value << '\n';
    }

    return os;
}
