#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

template <typename T, typename Compare = std::less<T>>
class BinaryHeap
{
public:
    constexpr BinaryHeap() = default;

    BinaryHeap(const BinaryHeap &rhs) : m_container(rhs.m_container), m_indexMap(rhs.m_indexMap) {}

    BinaryHeap(BinaryHeap &&rhs) noexcept : m_container(std::move(rhs.m_container)), m_indexMap(std::move(rhs.m_indexMap)) {}

    ~BinaryHeap() = default;

    BinaryHeap<T, Compare> &operator=(const BinaryHeap<T, Compare> &rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        this->m_container = rhs.m_container;
        this->m_indexMap = rhs.m_indexMap;
        return *this;
    }

    void insert(const T &element)
    {
        m_container.push_back(element);
        m_indexMap.emplace(std::make_pair(element, m_container.size() - 1));
        const auto parentIndex = getParentIndex(m_container.size() - 1);
        if (parentIndex >= 0)
        {
            bubbleUp(m_container.size() - 1, parentIndex);
        }
    }

    void arrayInsert(const std::vector<T> vec)
    {
        for (const auto &element : vec)
        {
            insert(element);
        }
    }

    void remove(const T &element)
    {
        const auto itr = m_indexMap.find(element);
        if (itr == m_indexMap.end())
        {
            return;
        }
        const auto index = itr->second;
        const auto last_index = m_container.size() - 1;
        swapElements(index, last_index);
        m_container.pop_back();
        dropIndex(element, last_index);
        bubbleDown(index);
    }

    void poll()
    {
        const auto &element = m_container[0];
        remove(element);
    }

    [[nodiscard]] const T &at(const int index) const
    {
        if (m_container.empty() || index < 0)
        {
            throw std::out_of_range("Index: " + std::to_string(index) + " out of range\n");
        }
        return m_container.at(index);
    }

    [[nodiscard]] std::vector<T> container() const noexcept
    {
        return m_container;
    }

    [[nodiscard]] constexpr size_t size() const noexcept
    {
        return m_container.size();
    }

    [[nodiscard]] constexpr bool isEmpty() const noexcept
    {
        return m_container.empty();
    }

    void clear()
    {
        m_indexMap.clear();
        m_container.clear();
    }

private:
    [[nodiscard]] int getParentIndex(const int childIndex) const
    {
        if (childIndex < 0)
        {
            throw std::out_of_range("Invalid child index: " + std::to_string(childIndex) + " to get the parent\n");
        }
        if (childIndex == 0)
        {
            return -1;
        }
        const auto parent_index = (childIndex - 1) / 2;
        return parent_index;
    }

    [[nodiscard]] int getChildIndex(const int parentIndex, const unsigned childRoll) const
    {
        if (parentIndex < 0 || parentIndex >= m_container.size())
        {
            throw std::out_of_range("Invalid parent index: " + std::to_string(parentIndex) + " to get child\n");
        }
        if (childRoll != 1 && childRoll != 2)
        {
            throw std::out_of_range("Invalid child roll: " + std::to_string(childRoll) + " to get child\n");
        }
        const auto childIndex = 2 * parentIndex + childRoll;
        if (childIndex >= m_container.size())
        {
            return -1;
        }
        return childIndex;
    }

    void swapElements(const unsigned index1, const unsigned index2)
    {
        if (index1 == index2)
        {
            throw std::invalid_argument("1st Index: " + std::to_string(index1) + "2nd Index " + std::to_string(index2) + ": invalid for swapping\n");
        }
        auto temp = m_container[index1];
        m_container[index1] = m_container[index2];
        m_container[index2] = temp;
        swapIndices(index1, index2);
    }

    void swapIndices(const unsigned index1, const unsigned index2)
    {
        const auto &element1 = m_container.at(index1);
        const auto &element2 = m_container.at(index2);
        auto itr1 = m_indexMap.end();
        auto itr2 = m_indexMap.end();
        auto count = 0;
        auto range = m_indexMap.equal_range(element1);
        for (auto itr = range.first; itr != range.second && count < 2; ++itr)
        {
            if (itr->second == index1)
            {
                itr1 = itr;
                ++count;
            }
            // if different indices of two elements with the same value being swapped here
            else if (itr->second == index2)
            {
                itr2 = itr;
                ++count;
            }
        }
        if (count < 2)
        {
            range = m_indexMap.equal_range(element2);
            // values are swapped already, check which index (1 or 2) to compare
            const auto index_to_compare = (itr1 == m_indexMap.end()) ? index1 : index2;
            for (auto itr = range.first; itr != range.second && count < 2; ++itr)
            {
                if (itr->second == index_to_compare)
                {
                    // check which iterator (1 or 2) needs to be assigned
                    if (itr2 == m_indexMap.end())
                    {
                        itr2 = itr;
                        ++count;
                    }
                    else if (itr1 == m_indexMap.end())
                    {
                        itr1 = itr;
                        ++count;
                    }
                }
            }
        }
        const auto temp = itr1->second;
        itr1->second = itr2->second;
        itr2->second = temp;
    }

    void dropIndex(const T &element, const unsigned index)
    {
        const auto &rng = m_indexMap.equal_range(element);
        for (auto itr = rng.first; itr != rng.second; ++itr)
        {
            const auto idx = itr->second;
            if (idx == index)
            {
                m_indexMap.erase(itr);
                break;
            }
        }
    }

    void bubbleUp(const int childIndex, const int parentIndex)
    {
        if (parentIndex < 0 || parentIndex >= m_container.size())
        {
            throw std::out_of_range("Parent index: " + std::to_string(parentIndex) + " for bubble up");
        }
        if (childIndex < 0 || parentIndex >= m_container.size())
        {
            throw std::out_of_range("Child index: " + std::to_string(parentIndex) + " for bubble up");
        }
        auto childIdx = childIndex;
        auto parentIdx = parentIndex;
        auto pChild = &m_container[childIdx];
        auto pParent = &m_container[parentIdx];
        while (compare(*pChild, *pParent))
        {
            swapElements(childIdx, parentIdx);
            childIdx = parentIdx;
            parentIdx = getParentIndex(childIdx);
            if (parentIdx < 0)
            {
                break;
            }
            pParent = &m_container[parentIdx];
            pChild = &m_container[childIdx];
        }
    }

    void bubbleDown(const int parentIndex)
    {
        if (parentIndex < 0 || parentIndex >= m_container.size())
        {
            throw std::out_of_range("Parent index: " + std::to_string(parentIndex) + " for bubble down");
        }
        auto parentIdx = parentIndex;
        while (true)
        {
            const auto pParent = &m_container[parentIdx];
            const auto child1_index = getChildIndex(parentIdx, 1);
            if (child1_index < 0)
            {
                break;
            }
            const auto pChild1 = &m_container[child1_index];
            const auto child2_index = getChildIndex(parentIdx, 2);
            if (child2_index < 0)
            {
                if (compare(*pChild1, *pParent))
                {
                    // only one child
                    swapElements(parentIdx, child1_index);
                    parentIdx = child1_index;
                }
                break;
            }
            const auto pChild2 = &m_container[child2_index];
            if (!compare(*pChild1, *pParent) && !compare(*pChild2, *pParent))
            {
                break;
            }
            if (compare(*pChild1, *pParent) && compare(*pChild2, *pParent))
            {
                if (compare(*pChild1, *pChild2))
                {
                    swapElements(parentIdx, child1_index);
                    parentIdx = child1_index;
                    continue;
                }
                swapElements(parentIdx, child2_index);
                parentIdx = child2_index;
                continue;
            }
            if (compare(*pChild1, *pParent))
            {
                swapElements(parentIdx, child1_index);
                parentIdx = child1_index;
                continue;
            }
            swapElements(parentIdx, child2_index);
            parentIdx = child2_index;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const BinaryHeap<T, Compare> &binHeap)
    {
        auto count = 0;
        for (const auto &elem : binHeap.m_container)
        {
            os << elem;
            (count < binHeap.size() - 1) ? os << ", " : os << '\n';
            ++count;
        }
        return os;
    }

    std::vector<T> m_container;
    std::unordered_multimap<T, int> m_indexMap;
    Compare compare;
};
