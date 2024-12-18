#include "BinaryHeap.hpp"

template <typename T, typename Compare = std::less<T>>
class PriorityQueue
{
public:
    constexpr PriorityQueue() = default;

    constexpr PriorityQueue(const PriorityQueue &rhs) : m_binHeap(rhs.m_binHeap) {}

    constexpr PriorityQueue(PriorityQueue &&rhs) noexcept : m_binHeap(std::move(rhs.m_binHeap)) {}

    ~PriorityQueue() = default;

    PriorityQueue<T, Compare> &operator=(const PriorityQueue<T, Compare> &rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        m_binHeap = rhs.m_binHeap;
        return *this;
    }

    void push(const T &element)
    {
        m_binHeap.insert(element);
    }

    void arrayPush(const std::vector<T> &vec)
    {
        m_binHeap.arrayInsert(vec);
    }

    [[nodiscard]] const T &top() const
    {
        if (m_binHeap.isEmpty())
        {
            throw std::out_of_range("Empty queue for access the top\n");
        }
        return m_binHeap.at(0);
    }

    void remove(const T &element)
    {
        if (m_binHeap.isEmpty())
        {
            throw std::out_of_range("Empty queue to remove an element\n");
        }
        m_binHeap.remove(element);
    }

    void pop()
    {
        m_binHeap.poll();
    }

    [[nodiscard]] std::vector<T> container() const noexcept
    {
        return m_binHeap.container();
    }

    [[nodiscard]] constexpr size_t size() const noexcept
    {
        return m_binHeap.size();
    }

    [[nodiscard]] constexpr bool isEmpty() const noexcept
    {
        return m_binHeap.isEmpty();
    }

    void clear()
    {
        m_binHeap.clear();
    }

private:
    BinaryHeap<T, Compare> m_binHeap;
};
