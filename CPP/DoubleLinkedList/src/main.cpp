#include "LinkedList.hpp"

#include <iomanip>

int main()
{
    LinkedList linkedList;
    linkedList.addLast(10);
    linkedList.addLast(20);
    linkedList.addFirst(5);
    std::cout << linkedList;
    std::cout << "The size of list: " << linkedList.getSize() << '\n';
    auto value = 5;
    std::cout << "Index of " << value << ": " << linkedList.indexOf(value) << '\n';
    std::cout << std::boolalpha << "Contains " << value << ": " << linkedList.contains(value) << '\n' << std::noboolalpha;
    linkedList.removeFirst();
    std::cout << "The size of list: " << linkedList.getSize() << '\n';
    linkedList.removeFirst();
    std::cout << "The size of list: " << linkedList.getSize() << '\n';
    linkedList.removeFirst();
    std::cout << "The size of list: " << linkedList.getSize() << '\n';
    linkedList.removeFirst();
    std::cout << "The size of list: " << linkedList.getSize() << '\n';

    linkedList.addLast(10);
    linkedList.addLast(20);
    linkedList.addFirst(5);
    std::cout << "The size of list: " << linkedList.getSize() << '\n';
    linkedList.removeLast();
    std::cout << "The size of list: " << linkedList.getSize() << '\n';
    linkedList.removeLast();
    std::cout << "The size of list: " << linkedList.getSize() << '\n';
    linkedList.removeLast();
    std::cout << "The size of list: " << linkedList.getSize() << '\n';
    linkedList.removeLast();
    std::cout << "The size of list: " << linkedList.getSize() << '\n';
    std::cout << '\n';

    linkedList.addLast(10);
    linkedList.addLast(20);
    linkedList.addFirst(5);
    std::cout << "Before removing node 10:\n" << linkedList;
    linkedList.remove(10);
    std::cout << "After removing node 10:\n" << linkedList;
    linkedList.remove(5);
    std::cout << "After removing node 5:\n" << linkedList;
    linkedList.remove(20);
    std::cout << "After removing node 20:\n" << linkedList;
    std::cout << '\n';

    linkedList.addLast(10);
    linkedList.addLast(20);
    linkedList.addFirst(5);
    auto int_arr = linkedList.toArray();
    std::cout << "To array:\n";
    for (auto idx = 0; idx < linkedList.getSize(); ++idx) {
        std::cout << int_arr[idx] << '\n';
    }
    std::cout << '\n';
    std::cout << "Current linked list:\n" << linkedList << '\n';
    linkedList.reverse();
    std::cout << "Reversed linked list:\n" << linkedList << '\n';
    
    value = 3;
    std::cout << value << "th node: " << linkedList.getKthNodeFromTheEnd(value) << '\n';
    linkedList.reverse();
    std::cout << "Re-reversed linked list:\n" << linkedList << '\n';
    std::cout << value << "th node: " << linkedList.getKthNodeFromTheEnd(value) << '\n';

    return 0;
}
