#include "LinkedList.hpp"

#include <iomanip>

int main()
{
    LinkedList<double> linkedList;
    linkedList.addLast(10.0);
    linkedList.addLast(20.0);
    linkedList.addFirst(5.0);
    try
    {
        std::cout << "Current list:\n"
                  << linkedList << '\n';
        std::cout << "Adding 15.5 at position 2:\n";
        linkedList.addAt(2, 15.5);
        std::cout << "Current list:\n"
                  << linkedList << '\n';
        std::cout << "Adding 25.5 at position 4:\n";
        linkedList.addAt(4, 25.5);
        std::cout << "Current list:\n"
                  << linkedList << '\n';
        std::cout << "Adding 1.0 at position 0:\n";
        linkedList.addAt(0, 1.0);
        std::cout << "Current list:\n"
                  << linkedList << '\n';
        std::cout << "Adding 30.0 at position 10:\n";
        linkedList.addAt(10, 30.0);
        std::cout << "Current list:\n"
                  << linkedList << '\n';
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what();
    }

    try
    {
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        std::cout << "Index of 5.0: " << linkedList.indexOf(5.0) << '\n';
        std::cout << std::boolalpha << "Contains 5.0: " << linkedList.contains(5.0) << '\n'
                  << std::noboolalpha;
        std::cout << "Removing the first item:\n";
        linkedList.removeFirst();
        std::cout << "Current list:\n"
                  << linkedList << '\n';
        std::cout << "Removing the first item:\n";
        linkedList.removeFirst();
        std::cout << "Current list:\n"
                  << linkedList << '\n';
        std::cout << "Removing the first item:\n";
        linkedList.removeFirst();
        std::cout << "Current list:\n"
                  << linkedList << '\n';
        std::cout << "Removing the first item:\n";
        linkedList.removeFirst();
        std::cout << "Current list:\n"
                  << linkedList << '\n';
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << '\n';

    linkedList.addLast(10.5);
    linkedList.addLast(20.5);
    linkedList.addFirst(5.5);
    try
    {
        std::cout << "Removing the last item:\n";
        linkedList.removeLast();
        std::cout << "Current list:\n"
                  << linkedList << '\n';
        std::cout << "Removing the last item:\n";
        linkedList.removeLast();
        std::cout << "Current list:\n"
                  << linkedList << '\n';
        std::cout << "Removing the last item:\n";
        linkedList.removeLast();
        std::cout << "Current list:\n"
                  << linkedList << '\n';
        std::cout << "Removing the last item:\n";
        linkedList.removeLast();
        std::cout << "Current list:\n"
                  << linkedList << '\n';
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << '\n';

    linkedList.addLast(10.0);
    linkedList.addLast(20.0);
    linkedList.addFirst(5.0);
    try
    {
        std::cout << "Before removing node 10.0:\n"
                  << linkedList;
        linkedList.remove(10.0);
        std::cout << "After removing node 10.0:\n"
                  << linkedList;
        linkedList.remove(5.0);
        std::cout << "After removing node 5.0:\n"
                  << linkedList;
        linkedList.remove(20.0);
        std::cout << "After removing node 20.0:\n"
                  << linkedList;
        linkedList.remove(50.0);
        std::cout << "After removing node 50.0:\n"
                  << linkedList;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << '\n';

    linkedList.addLast(10.6);
    linkedList.addLast(20.6);
    linkedList.addFirst(5.6);
    try
    {
        linkedList.addAt(2, 15.6);
        std::cout << "The list:\n"
                  << linkedList << '\n';
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        auto pos = 1;
        linkedList.removeAt(pos);
        std::cout << "After removing node at position: " << pos << '\n'
                  << linkedList;
        pos = 2;
        linkedList.removeAt(pos);
        std::cout << "After removing node at position: " << pos << '\n'
                  << linkedList;
        pos = 1;
        linkedList.removeAt(pos);
        std::cout << "After removing node at position: " << pos << '\n'
                  << linkedList;
        pos = 0;
        linkedList.removeAt(pos);
        std::cout << "After removing node at position: " << pos << '\n'
                  << linkedList;
        pos = linkedList.getSize() - 1;
        linkedList.removeAt(pos);
        std::cout << "After removing node at position: " << pos << '\n'
                  << linkedList;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << '\n';

    linkedList.addLast(10.7);
    linkedList.addLast(20.7);
    linkedList.addFirst(5.7);
    auto int_arr = linkedList.toArray();
    std::cout << "To array:\n";
    for (auto idx = 0; idx < linkedList.getSize(); ++idx)
    {
        std::cout << int_arr[idx] << '\n';
    }
    std::cout << '\n';
    std::cout << "Current linked list:\n"
              << linkedList << '\n';
    linkedList.reverse();
    std::cout << "Reversed linked list:\n"
              << linkedList << '\n';

    try
    {
        auto value = 3;
        std::cout << value << "rd node from the end: " << linkedList.getKthNodeFromTheEnd(value) << '\n';
        linkedList.reverse();
        std::cout << "Re-reversed linked list:\n"
                  << linkedList << '\n';
        std::cout << value << "rd node from the end: " << linkedList.getKthNodeFromTheEnd(value) << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << '\n';
    std::cout << "List to string:\n"
              << linkedList.toString() << '\n';
    std::cout << '\n';

    try
    {
        linkedList.addAt(2, 15.3);
        linkedList.addLast(25.3);
        linkedList.addLast(30.3);
        std::cout << "Current linked list:\n"
                  << linkedList << '\n';
        const auto &val_01 = linkedList.at(0);
        std::cout << "At position 0: " << val_01 << '\n';
        const auto &val_03 = linkedList.at(3);
        std::cout << "At position 3: " << val_03 << '\n';
        const auto &val_05 = linkedList.at(5);
        std::cout << "At position 5: " << val_05 << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

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

    std::cout << "Changing the first node value:\n";
    auto itr_begin = linkedList.begin();
    *itr_begin = 99.99;
    std::cout << "Current linked list after changing the first node value:\n"
              << linkedList << '\n';

    std::cout << "Clearing the list:\n";
    linkedList.clear();
    std::cout << "List to string:\n"
              << linkedList.toString() << '\n';
    std::cout << "The size of list: " << linkedList.getSize() << '\n';

    return 0;
}
