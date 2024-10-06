#include "LinkedList.hpp"

#include <iomanip>

int main()
{
    LinkedList linkedList;
    auto value = INVALID_NODE_VALUE;
    linkedList.addLast(10);
    linkedList.addLast(20);
    linkedList.addFirst(5);    
    try
    {
        std::cout << "List before adding 15 at position 2:\n"
                  << linkedList << '\n';
        linkedList.addAt(2, 15);
        std::cout << "List after adding 15 at position 2:\n"
                  << linkedList << '\n';
        linkedList.addAt(4, 25);
        std::cout << "List after adding 25 at position 4:\n"
                  << linkedList << '\n';
        linkedList.addAt(0, 1);
        std::cout << "List after adding 1 at position 0:\n"
                  << linkedList << '\n';
        linkedList.addAt(10, 30);
        std::cout << "List after adding 30 at position 10:\n"
                  << linkedList << '\n';
    }
    catch (const std::exception& ex) {
        std::cout << ex.what();
    }

    try
    {
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        value = 5;
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

    linkedList.addLast(10);
    linkedList.addLast(20);
    linkedList.addFirst(5);
    try
    {
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
        value = linkedList.removeLast();
        std::cout << "Last item: " << value << " removed\n";
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << '\n';

    linkedList.addLast(10);
    linkedList.addLast(20);
    linkedList.addFirst(5);
    try
    {
        std::cout << "Before removing node 10:\n"
                  << linkedList;
        linkedList.remove(10);
        std::cout << "After removing node 10:\n"
                  << linkedList;
        linkedList.remove(5);
        std::cout << "After removing node 5:\n"
                  << linkedList;
        linkedList.remove(20);
        std::cout << "After removing node 20:\n"
                  << linkedList;
        linkedList.remove(50);
        std::cout << "After removing node 50:\n"
                  << linkedList;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << '\n';

    linkedList.addLast(10);
    linkedList.addLast(20);
    linkedList.addFirst(5);
    try
    {
        linkedList.addAt(2, 15);
        std::cout << "The list:\n"
                  << linkedList << '\n';
        std::cout << "The size of list: " << linkedList.getSize() << '\n';
        value = linkedList.removeAt(1);
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
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
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

    try
    {
        value = 3;
        std::cout << value << "rd node from the end: " << linkedList.getKthNodeFromTheEnd(value) << '\n';
        linkedList.reverse();
        std::cout << "Re-reversed linked list:\n"
                  << linkedList << '\n';
        std::cout << value << "rd node from the end: " << linkedList.getKthNodeFromTheEnd(value) << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << '\n';

    std::cout << "List to string:\n" << linkedList.toString() << '\n';
    std::cout << '\n';

    return 0;
}
