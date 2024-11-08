#include "Stack.hpp"

int main()
{
    StackInSingleLinkedList stack;
    std::cout << "Initial stack\n";
    stack.printStack();
    std::cout << "***************\n\n";
    stack.push(10);
    std::cout << "After pushing 10\n";
    stack.printStack();
    std::cout << "***************\n\n";
    stack.push(15);
    std::cout << "After pushing 15\n";
    stack.printStack();
    std::cout << "***************\n\n";

    return 0;
}
