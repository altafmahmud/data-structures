#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <optional>
#include <stdexcept>

template <typename T, typename Compare = std::less<T>>
class BinaryHeap
{
public:
    constexpr BinaryHeap() = default;
    BinaryHeap(const BinaryHeap &rhs)
    {
        const auto &rhs_container = rhs.getContainer();
        std::copy(rhs_container.cbegin(), rhs_container.cend(), std::back_inserter(this->m_container));
    }
    ~BinaryHeap() = default;

    void insert(const T &element)
    {
        m_container.push_back(element);
        m_indexMap.emplace(std::make_pair(element, m_container.size() - 1));
        const auto &parent_opt = getParent(m_container.size() - 1);
        if (parent_opt.has_value())
        {
            const auto &parent_idx_pair = parent_opt.value();
            const auto parentIdx = parent_idx_pair.second;
            bubbleUp(m_container.size() - 1, parentIdx);
        }
    }

    void bulkInsert(const std::vector<T> vec)
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

    void bubbleUp(const unsigned childIndex, const unsigned parentIndex)
    {
        auto childIdx = childIndex;
        auto parentIdx = parentIndex;
        const auto child = m_container[childIdx];
        auto parent = m_container[parentIdx];
        while (compare(child, parent))
        {
            swapElements(childIdx, parentIdx);
            childIdx = parentIdx;
            const auto &parent_opt = getParent(childIdx);
            if (!parent_opt.has_value())
            {
                break;
            }
            const auto &parent_idx_pair = parent_opt.value();
            parent = parent_idx_pair.first;
            parentIdx = parent_idx_pair.second;
        }
    }

    void bubbleDown(const unsigned parentIndex)
    {
        if (parentIndex >= m_container.size())
        {
            throw std::out_of_range("Parent index: " + std::to_string(parentIndex) + " for bubble up");
        }
        auto parentIdx = parentIndex;
        while (true)
        {
            const auto &parent = m_container[parentIdx];
            const auto child1_opt = getChild(parentIdx, 1);
            if (!child1_opt.has_value())
            {
                break;
            }
            const auto child1_index_pair = child1_opt.value();
            const auto child1 = child1_index_pair.first;
            const auto child1_index = child1_index_pair.second;
            const auto child2_opt = getChild(parentIdx, 2);
            if (!child2_opt.has_value())
            {
                if (compare(child1, parent))
                {
                    // only one child
                    swapElements(parentIdx, child1_index);
                    parentIdx = child1_index;
                }
                break;
            }
            const auto child2_index_pair = child2_opt.value();
            const auto child2 = child2_index_pair.first;
            const auto child2_index = child2_index_pair.second;
            if (!compare(child1, parent) && !compare(child2, parent))
            {
                break;
            }
            if (compare(child1, parent) && compare(child2, parent))
            {
                if (compare(child1, child2))
                {
                    swapElements(parentIdx, child1_index);
                    parentIdx = child1_index;
                    continue;
                }
                swapElements(parentIdx, child2_index);
                parentIdx = child2_index;
                continue;
            }
            if (compare(child1, parent))
            {
                swapElements(parentIdx, child1_index);
                parentIdx = child1_index;
                continue;
            }
            swapElements(parentIdx, child2_index);
            parentIdx = child2_index;
        }
    }

    void print() const
    {
        std::cout << *this;
    }

    [[nodiscard]] const std::vector<T> &container() const noexcept
    {
        return m_container;
    }

    [[nodiscard]] constexpr size_t size() const noexcept
    {
        return m_container.size();
    }

    [[nodiscard]] constexpr bool isEmpty() const noexcept
    {
        return m_container.isEmpty();
    }

    void clear()
    {
        m_container.clear();
    }

private:
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

    [[nodiscard]] std::optional<std::pair<const T &, unsigned>> getParent(const unsigned childIndex) const
    {
        if (childIndex == 0)
        {
            return {};
        }
        const auto parent_index = (childIndex - 1) / 2;
        const auto &parent = m_container[parent_index];
        const auto parent_idx_pair = std::make_pair(parent, parent_index);
        return std::make_optional(parent_idx_pair);
    }

    [[nodiscard]] std::optional<std::pair<const T &, unsigned>> getChild(const unsigned parentIndex, const unsigned childRoll) const
    {
        const auto childIndex = 2 * parentIndex + childRoll;
        if (childIndex >= m_container.size())
        {
            return {};
        }
        const auto &child = m_container[childIndex];
        const auto &child_idx_pair = std::make_pair(child, childIndex);
        return std::make_optional(child_idx_pair);
    }

    void swapElements(const unsigned index1, const unsigned index2)
    {
        if (index1 == index2)
        {
            return;
        }
        auto temp = m_container[index1];
        m_container[index1] = m_container[index2];
        m_container[index2] = temp;
        swapIndices(index1, index2);
    }

    void swapIndices(const unsigned index1, const unsigned index2)
    {
        auto itr1 = m_indexMap.end();
        auto itr2 = m_indexMap.end();
        auto count = 0;
        for (auto itr = m_indexMap.begin(); itr != m_indexMap.end(); ++itr)
        {
            if (itr->second == index1)
            {
                itr1 = itr;
                ++count;
            }
            else if (itr->second == index2)
            {
                itr2 = itr;
                ++count;
            }
            if (count == 2)
            {
                break;
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

    std::vector<T> m_container;
    std::unordered_multimap<T, unsigned> m_indexMap;
    Compare compare;
};
