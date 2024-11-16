#include "LinkedList.hpp"

#include <iomanip>

int main()
{
    LinkedList<float> linkedList;
    linkedList.addLast(10);
    linkedList.addLast(20);
    linkedList.addFirst(5);
    std::cout << linkedList;
    std::cout << "The size of list: " << linkedList.getSize() << '\n';
    auto value = 5;
    std::cout << "Index of " << value << ": " << linkedList.indexOf(value) << '\n';
    std::cout << std::boolalpha << "Contains " << value << ": " << linkedList.contains(value) << '\n'
              << std::noboolalpha;
    try
    {
        auto del_val = linkedList.removeFirst();
        std::cout << "First item: " << del_val << " removed\n";
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        del_val = linkedList.removeFirst();
        std::cout << "First item: " << del_val << " removed\n";
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        del_val = linkedList.removeFirst();
        std::cout << "First item: " << del_val << " removed\n";
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        del_val = linkedList.removeFirst();
        std::cout << "First item: " << del_val << " removed\n";
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
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
    try
    {
        linkedList.addAt(7, 35);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "The list after trying to add 35 at index 7:\n"
              << linkedList << '\n';
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    try
    {
        linkedList.addAt(-1, 35);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "The list after trying to add 35 at index -1:\n"
              << linkedList << '\n';
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    std::cout << '\n';

    linkedList.addLast(10);
    linkedList.addLast(20);
    linkedList.addFirst(5);
    std::cout << "Current list:\n"
              << linkedList << '\n';
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    try
    {
        auto del_val = linkedList.removeAt(1);
        std::cout << "Current list after removing " << del_val << " from position: 1\n"
                  << linkedList << '\n';
        std::cout << "The size of the list: " << linkedList.getSize() << '\n';
        del_val = linkedList.removeAt(4);
        std::cout << "Current list after removing " << del_val << " from position: 4\n"
                  << linkedList << '\n';
        std::cout << "The size of the list: " << linkedList.getSize() << '\n';
        del_val = linkedList.removeAt(0);
        std::cout << "Current list after removing " << del_val << " from position: 0\n"
                  << linkedList << '\n';
        std::cout << "The size of the list: " << linkedList.getSize() << '\n';
        del_val = linkedList.removeAt(5);
        std::cout << "Current list after removing " << del_val << " from position: 5\n"
                  << linkedList << '\n';
        std::cout << "The size of the list: " << linkedList.getSize() << '\n';
        del_val = linkedList.removeAt(5);
        std::cout << "Current list after removing " << del_val << " from position: 5\n"
                  << linkedList << '\n';
        std::cout << "The size of the list: " << linkedList.getSize() << '\n';
        del_val = linkedList.removeAt(-1);
        std::cout << "Current list after removing " << del_val << " from position: -1\n"
                  << linkedList << '\n';
        std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    std::cout << "The size of the list: " << linkedList.getSize() << '\n';
    std::cout << '\n';

    linkedList.addLast(10);
    linkedList.addLast(20);
    linkedList.addFirst(5);
    try
    {
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        auto del_val = linkedList.removeLast();
        std::cout << "Last item: " << del_val << " removed\n";
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        del_val = linkedList.removeLast();
        std::cout << "Last item: " << del_val << " removed\n";
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        del_val = linkedList.removeLast();
        std::cout << "Last item: " << del_val << " removed\n";
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        del_val = linkedList.removeLast();
        std::cout << "Last item: " << del_val << " removed\n";
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << '\n';

    linkedList.addLast(10);
    linkedList.addLast(20);
    linkedList.addFirst(5);
    const auto int_arr = linkedList.toArray();
    std::cout << "To array:\n";
    for (auto idx = 0; idx < linkedList.getSize(); ++idx)
    {
        std::cout << int_arr[idx] << '\n';
    }

    std::cout << "Current linked list:\n"
              << linkedList << '\n';
    std::cout << "List to string:\n"
              << linkedList.toString() << '\n';
    linkedList.reverse();
    std::cout << "Reversed linked list:\n"
              << linkedList << '\n';
    std::cout << "List to string:\n"
              << linkedList.toString() << '\n';
    linkedList.reverse();

    std::cout << "Current linked list:\n"
              << linkedList << '\n';
    std::cout << "List to string:\n"
              << linkedList.toString() << '\n';
    auto &kth_node_01 = linkedList.getKthNodeFromTheEnd(2);
    std::cout << "2nd node from the end: " << kth_node_01 << '\n';
    linkedList.reverse();
    std::cout << "Reversed linked list:\n"
              << linkedList << '\n';
    std::cout << "List to string:\n"
              << linkedList.toString() << '\n';
    auto &kth_node_02 = linkedList.getKthNodeFromTheEnd(2);
    std::cout << "2nd node from the end: " << kth_node_02 << '\n';
    kth_node_02 = 50;
    std::cout << "Current linked list after changing the 2nd node value:\n"
              << linkedList << '\n';
    std::cout << '\n';

    try
    {
        std::cout << "Iterating list:\n";
        for (auto iterator = linkedList.begin(); iterator != linkedList.end(); ++iterator)
        {
            std::cout << *iterator << ' ';
        }
        std::cout << "\n\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Value at position 4:\n"
              << linkedList.at(4) << '\n';
    std::cout << '\n';

    LinkedList<float> linkedListMovedCtr(std::move(linkedList));
    std::cout << "Moved constructor Linked List:\n"
              << linkedListMovedCtr << '\n';

    LinkedList<float> linkedListMoved;
    linkedListMoved = std::move(linkedListMovedCtr);
    std::cout << "Move assigned Linked List:\n"
              << linkedListMoved << '\n';

    return 0;
}
