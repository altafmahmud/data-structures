#include "PriorityQueue.hpp"

template <typename T>
void printPQ(const std::vector<T> &vec)
{
    std::cout << '[';
    std::copy(vec.cbegin(), vec.cend() - 1, std::ostream_iterator<T>(std::cout, ","));
    std::cout << vec.back() << "]\n";
}

int main()
{
    PriorityQueue<int> minQueue;
    minQueue.push(11);
    minQueue.push(17);
    minQueue.push(10);
    minQueue.push(2);
    minQueue.push(5);
    minQueue.push(3);
    minQueue.push(7);
    std::cout << "Min PQ after pushing some values:\n";
    printPQ(minQueue.container());
    const auto &minPQtop = minQueue.top();
    std::cout << "Min PQ top: " << minPQtop << '\n';
    minQueue.remove(2);
    std::cout << "Min PQ after removing the value 2:\n";
    printPQ(minQueue.container());
    minQueue.pop();
    std::cout << "Min PQ after pop:\n";
    printPQ(minQueue.container());

    PriorityQueue<int, std::greater<int>> maxQueue;
    std::vector<int> int_vec = {2, 5, 3, 17, 10, 11, 7};
    maxQueue.bulkPush(int_vec);
    std::cout << "Max PQ after pushing some values:\n";
    printPQ(maxQueue.container());
    const auto &maxPQtop = maxQueue.top();
    std::cout << "Max PQ top: " << maxPQtop << '\n';
    maxQueue.remove(17);
    std::cout << "Max PQ after removing the value 17:\n";
    printPQ(maxQueue.container());
    maxQueue.pop();
    std::cout << "Max PQ after pop:\n";
    printPQ(maxQueue.container());
    return 0;
}
