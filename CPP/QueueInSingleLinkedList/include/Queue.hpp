#include "SingleLinkedList.hpp"

template <typename T>
class QueueInSingleLinkedList
{
private:
    LinkedList<T> m_singleLinkedList;

public:
    constexpr QueueInSingleLinkedList() = default;

    constexpr QueueInSingleLinkedList(const QueueInSingleLinkedList &) = delete;

    QueueInSingleLinkedList(const QueueInSingleLinkedList<T> &&rhs): QueueInSingleLinkedList()
    {
        m_singleLinkedList = std::move(rhs.m_singleLinkedList);
    }

    ~QueueInSingleLinkedList() = default;

    QueueInSingleLinkedList<T> &operator=(QueueInSingleLinkedList<T> &&rhs)
    {
        clear();
        m_singleLinkedList = std::move(rhs.m_singleLinkedList);
        return *this;
    }

    constexpr bool isEmpty() const noexcept
    {
        return m_singleLinkedList.isEmpty();
    }

    void enqueue(const T &value)
    {
        m_singleLinkedList.addLast(value);
    }

    void dequeue()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Empty queue");
        }
        m_singleLinkedList.removeFirst();
    }

    const T &peek() const
    {
        if (isEmpty())
        {
            throw std::out_of_range("Empty queue");
        }
        const auto &value = m_singleLinkedList.at(0);
        return value;
    }

    constexpr int getSize() const noexcept
    {
        return m_singleLinkedList.getSize();
    }

    void printQueue(const bool toString = false) const
    {
        (toString) ? std::cout << m_singleLinkedList.toString() << '\n' : std::cout << m_singleLinkedList << '\n';
    }

    int clear()
    {
        return m_singleLinkedList.clear();
    }
};
