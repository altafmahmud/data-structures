#include "SingleLinkedList.hpp"

class QueueInSingleLinkedList
{
private:
    LinkedList m_singleLinkedList;

public:
    QueueInSingleLinkedList() = default;
    QueueInSingleLinkedList(const QueueInSingleLinkedList &) = delete;
    ~QueueInSingleLinkedList() = default;

    constexpr bool isEmpty() const noexcept
    {
        return m_singleLinkedList.isEmpty();
    }

    void enqueue(const int);
    void dequeue();
    const int &peek() const;

    constexpr int getSize() const noexcept
    {
        return m_singleLinkedList.getSize();
    }

    void printQueue(const bool toString = false) const;
};
