#include "BinaryHeap.hpp"

int main()
{
    BinaryHeap<int> binMinHeap;
    std::vector<int> int_vec = {11, 12, 13, 19, 14, 5, 7, 8, 12, 6};
    binMinHeap.bulkInsert(int_vec);
    std::cout << binMinHeap << '\n';
    binMinHeap.insert(1);
    binMinHeap.insert(13);
    binMinHeap.insert(4);
    binMinHeap.insert(0);
    binMinHeap.insert(10);
    std::cout << binMinHeap << '\n';
    binMinHeap.remove(1);
    std::cout << "After removing 1: " << binMinHeap << '\n';
    binMinHeap.poll();
    std::cout << "After polling: " << binMinHeap << '\n';
    
    BinaryHeap<int, std::greater<int>> binMaxHeap;
    binMaxHeap.bulkInsert(int_vec);
    std::cout << binMinHeap << '\n';
    binMaxHeap.insert(1);
    binMaxHeap.insert(13);
    binMaxHeap.insert(4);
    binMaxHeap.insert(0);
    binMaxHeap.insert(10);
    std::cout << binMaxHeap << '\n';
    binMaxHeap.remove(1);
    std::cout << "After removing 1: " << binMaxHeap << '\n';
    binMaxHeap.poll();
    std::cout << "After polling: " << binMaxHeap << '\n';
    return 0;
}
