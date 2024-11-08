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
        linkedList.addAt(2, 15.5);
        std::cout << "List after adding 15.5 at position 2:\n"
                  << linkedList << '\n';
        linkedList.addAt(4, 25.5);
        std::cout << "List after adding 25.5 at position 4:\n"
                  << linkedList << '\n';
        linkedList.addAt(0, 1.0);
        std::cout << "List after adding 1.0 at position 0:\n"
                  << linkedList << '\n';
        linkedList.addAt(10, 30.0);
        std::cout << "List after adding 30.0 at position 10:\n"
                  << linkedList << '\n';
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what();
    }

    try
    {
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        auto value = 5.0;
        std::cout << "Index of " << value << ": " << linkedList.indexOf(value) << '\n';
        std::cout << std::boolalpha << "Contains " << value << ": " << linkedList.contains(value) << '\n'
                  << std::noboolalpha;
        value = linkedList.removeFirst();
        std::cout << "First item: " << value << " removed\n";
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        value = linkedList.removeFirst();
        std::cout << "First item: " << value << " removed\n";
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        value = linkedList.removeFirst();
        std::cout << "First item: " << value << " removed\n";
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        value = linkedList.removeFirst();
        std::cout << "First item: " << value << " removed\n";
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
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        auto value = linkedList.removeLast();
        std::cout << "Last item: " << value << " removed\n";
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        value = linkedList.removeLast();
        std::cout << "Last item: " << value << " removed\n";
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        value = linkedList.removeLast();
        std::cout << "Last item: " << value << " removed\n";
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        value = linkedList.removeLast();
        std::cout << "Last item: " << value << " removed\n";
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
        auto value = linkedList.removeAt(1);
        std::cout << "After removing node: " << value << " at position: 1\n"
                  << linkedList;
        value = linkedList.removeAt(2);
        std::cout << "After removing node: " << value << " at position: 2\n"
                  << linkedList;
        value = linkedList.removeAt(1);
        std::cout << "After removing node: " << value << " at position: 1\n"
                  << linkedList;
        value = linkedList.removeAt(0);
        std::cout << "After removing node: " << value << " at position: 1\n"
                  << linkedList;
        value = linkedList.removeAt(linkedList.getSize() - 1);
        std::cout << "After removing node: " << value << " at position: 1\n"
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
        const auto &val_01 = linkedList.getAt(0);
        std::cout << "At position 0: " << val_01 << '\n';
        auto &val_03 = linkedList.getAt(3);
        std::cout << "At position 3: " << val_03 << '\n';
        auto &val_05 = linkedList.getAt(5);
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

    return 0;
}
