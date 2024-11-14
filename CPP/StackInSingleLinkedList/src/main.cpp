#include "Stack.hpp"

template <typename T>
void printStackDetails(const StackInSingleLinkedList<T> &stack)
{
    std::cout << "Stack:\n";
    stack.printStack();
    std::cout << "Stack in a string:\n";
    stack.printStack(true);
    try
    {
        std::cout << "Top of the stack: " << stack.top() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Stack size: " << stack.getSize() << '\n';
}

int main()
{
    try
    {
        StackInSingleLinkedList<int> stack;
        std::cout << "Initial stack\n";
        printStackDetails<int>(stack);
        std::cout << "***************\n\n";
        std::cout << "Pushing 10\n";
        stack.push(10);
        printStackDetails<int>(stack);
        std::cout << "***************\n\n";
        std::cout << "Pushing 15\n";
        stack.push(15);
        printStackDetails<int>(stack);
        std::cout << "***************\n\n";

        std::cout << "Popping: " << stack.top() << '\n';
        stack.pop();
        printStackDetails<int>(stack);
        std::cout << "***************\n\n";
        std::cout << "Popping: " << stack.top() << '\n';
        stack.pop();
        printStackDetails<int>(stack);
        std::cout << "***************\n\n";

        std::cout << "Pushing 5\n";
        stack.push(5);
        std::cout << "Pushing 15\n";
        stack.push(15);
        std::cout << "Pushing 25\n";
        stack.push(25);
        printStackDetails<int>(stack);
        std::cout << "***************\n\n";
        StackInSingleLinkedList<int> moveConstrStack(std::move(stack));
        std::cout << "Stack with move constructor\n";
        printStackDetails<int>(moveConstrStack);
        std::cout << "***************\n\n";
        StackInSingleLinkedList<int> movedStack;
        movedStack = std::move(moveConstrStack);
        std::cout << "Moved stack\n";
        printStackDetails<int>(movedStack);
        std::cout << "***************\n\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
