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
    std::cout << std::boolalpha << "Contains " << value << ": " << linkedList.contains(value) << '\n'
              << std::noboolalpha;
    linkedList.removeFirst();
    std::cout << "The size of list: " << linkedList.getSize() << '\n';
    linkedList.removeFirst();
    std::cout << "The size of list: " << linkedList.getSize() << '\n';
    linkedList.removeFirst();
    std::cout << "The size of list: " << linkedList.getSize() << '\n';
    linkedList.removeFirst();
    std::cout << "The size of list: " << linkedList.getSize() << '\n';
    std::cout << '\n';

    linkedList.addLast(10);
    linkedList.addLast(20);
    linkedList.addFirst(5);
    std::cout << "The list:\n"
              << linkedList << '\n';
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    linkedList.addAt(2, 15);
    std::cout << "The list after adding 15 at index 2:\n"
              << linkedList << '\n';
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    linkedList.addAt(4, 30);
    std::cout << "The list after adding 30 at index 4:\n"
              << linkedList << '\n';
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    linkedList.addAt(4, 25);
    std::cout << "The list after adding 25 at index 4:\n"
              << linkedList << '\n';
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    linkedList.addAt(7, 35);
    std::cout << "The list after trying to add 35 at index 7:\n"
              << linkedList << '\n';
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    linkedList.addAt(-1, 35);
    std::cout << "The list after trying to add 35 at index -1:\n"
              << linkedList << '\n';
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    std::cout << '\n';

    linkedList.addLast(10);
    linkedList.addLast(20);
    linkedList.addFirst(5);
    std::cout << "Current list:\n" << linkedList << '\n';
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    auto del_val = linkedList.removeAt(1);
    (del_val == INVALID_NODE_VALUE) ? std::cout << "Current list after trying to remove item from position: 1\n"
                                                << linkedList << '\n'
                                    : std::cout << "Current list after removing " << del_val << " from position: 1\n"
                                                << linkedList << '\n';
    ;
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    del_val = linkedList.removeAt(4);
    (del_val == INVALID_NODE_VALUE) ? std::cout << "Current list after trying to remove item from position: 4\n"
                                                << linkedList << '\n'
                                    : std::cout << "Current list after removing " << del_val << " from position: 4\n"
                                                << linkedList << '\n';
    ;
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    del_val = linkedList.removeAt(0);
    (del_val == INVALID_NODE_VALUE) ? std::cout << "Current list after trying to remove item from position: 0\n"
                                                << linkedList << '\n'
                                    : std::cout << "Current list after removing " << del_val << " from position: 0\n"
                                                << linkedList << '\n';
    ;
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    del_val = linkedList.removeAt(5);
    (del_val == INVALID_NODE_VALUE) ? std::cout << "Current list after trying to remove item from position: 5\n"
                                                << linkedList << '\n'
                                    : std::cout << "Current list after removing " << del_val << " from position: 5\n"
                                                << linkedList << '\n';
    ;
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    del_val = linkedList.removeAt(5);
    (del_val == INVALID_NODE_VALUE) ? std::cout << "Current list after trying to remove item from position: 5\n"
                                                << linkedList << '\n'
                                    : std::cout << "Current list after removing " << del_val << " from position: 5\n"
                                                << linkedList << '\n';
    ;
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    del_val = linkedList.removeAt(-1);
    (del_val == INVALID_NODE_VALUE) ? std::cout << "Current list after trying to remove item from position: -1\n"
                                                << linkedList << '\n'
                                    : std::cout << "Current list after removing " << del_val << " from position: -1\n"
                                                << linkedList << '\n';
    ;
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    std::cout << '\n';

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
    auto int_arr = linkedList.toArray();
    std::cout << "To array:\n";
    for (auto idx = 0; idx < linkedList.getSize(); ++idx)
    {
        std::cout << int_arr[idx] << '\n';
    }

    std::cout << "Current linked list:\n"
              << linkedList << '\n';
    std::cout << "List to string:\n" << linkedList.toString() << '\n';
    linkedList.reverse();
    std::cout << "Reversed linked list:\n"
              << linkedList << '\n';
    std::cout << "List to string:\n" << linkedList.toString() << '\n';
    linkedList.reverse();

    std::cout << "Current linked list:\n"
              << linkedList << '\n';
    std::cout << "List to string:\n" << linkedList.toString() << '\n';              
    value = 2;
    std::cout << value << "th node from the end: " << linkedList.getKthNodeFromTheEnd(value) << '\n';
    linkedList.reverse();
    std::cout << "Reversed linked list:\n"
              << linkedList << '\n';
    std::cout << "List to string:\n" << linkedList.toString() << '\n';          
    std::cout << value << "th node from the end: " << linkedList.getKthNodeFromTheEnd(value) << '\n';

    return 0;
}
