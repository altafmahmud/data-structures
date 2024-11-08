#include "Stack.hpp"

int main()
{
    QueueInSingleLinkedList stack;
    std::cout << "Initial stack\n";
    stack.printQueue();
    stack.printQueue(true);
    std::cout << "\n***************\n\n";
    stack.enqueue(10);
    std::cout << "After pushing 10\n";
    stack.printQueue();
    stack.printQueue(true);
    try
    {
        std::cout << "Top of the stack: " << stack.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what();
    }
    std::cout << "\nStack size: " << stack.getSize() << '\n';
    std::cout << "\n***************\n\n";
    stack.enqueue(15);
    std::cout << "After pushing 15\n";
    stack.printQueue();
    stack.printQueue(true);
    try
    {
        std::cout << "Top of the stack: " << stack.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what();
    }    
    std::cout << "\nStack size: " << stack.getSize() << '\n';
    std::cout << "\n***************\n\n";

    try
    {
        std::cout << "Top of the stack: " << stack.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what();
    }
    std::cout << "\n***************\n\n";

    stack.dequeue();
    std::cout << "After popping\n";
    stack.printQueue();
    stack.printQueue(true);
    try
    {
        std::cout << "Top of the stack: " << stack.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what();
    }
    std::cout << "\n***************\n\n";    
    std::cout << "\nStack size: " << stack.getSize() << '\n';
    std::cout << "\n***************\n\n";
    stack.dequeue();
    std::cout << "After popping\n";
    stack.printQueue();
    stack.printQueue(true);
    try
    {
        std::cout << "Top of the stack: " << stack.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what();
    }
    std::cout << "\n***************\n\n";    
    std::cout << "\nStack size: " << stack.getSize() << '\n';
    std::cout << "\n***************\n\n";
    stack.dequeue();
    std::cout << "After popping\n";
    stack.printQueue();
    stack.printQueue(true);
    try
    {
        std::cout << "Top of the stack: " << stack.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what();
    }    
    std::cout << "\nStack size: " << stack.getSize() << '\n';
    std::cout << "\n***************\n\n";

    return 0;
}
