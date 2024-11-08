#include "Stack.hpp"

int main()
{
    StackInSingleLinkedList stack;
    std::cout << "Initial stack\n";
    stack.printStack();
    stack.printStack(true);
    std::cout << "\n***************\n\n";
    stack.push(10);
    std::cout << "After pushing 10\n";
    stack.printStack();
    stack.printStack(true);
    try
    {
        std::cout << "Top of the stack: " << stack.top() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what();
    }
    std::cout << "\nStack size: " << stack.getSize() << '\n';
    std::cout << "\n***************\n\n";
    stack.push(15);
    std::cout << "After pushing 15\n";
    stack.printStack();
    stack.printStack(true);
    try
    {
        std::cout << "Top of the stack: " << stack.top() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what();
    }    
    std::cout << "\nStack size: " << stack.getSize() << '\n';
    std::cout << "\n***************\n\n";

    try
    {
        std::cout << "Top of the stack: " << stack.top() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what();
    }
    std::cout << "\n***************\n\n";

    stack.pop();
    std::cout << "After popping\n";
    stack.printStack();
    stack.printStack(true);
    try
    {
        std::cout << "Top of the stack: " << stack.top() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what();
    }
    std::cout << "\n***************\n\n";    
    std::cout << "\nStack size: " << stack.getSize() << '\n';
    std::cout << "\n***************\n\n";
    stack.pop();
    std::cout << "After popping\n";
    stack.printStack();
    stack.printStack(true);
    try
    {
        std::cout << "Top of the stack: " << stack.top() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what();
    }
    std::cout << "\n***************\n\n";    
    std::cout << "\nStack size: " << stack.getSize() << '\n';
    std::cout << "\n***************\n\n";
    stack.pop();
    std::cout << "After popping\n";
    stack.printStack();
    stack.printStack(true);
    try
    {
        std::cout << "Top of the stack: " << stack.top() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what();
    }    
    std::cout << "\nStack size: " << stack.getSize() << '\n';
    std::cout << "\n***************\n\n";

    return 0;
}
