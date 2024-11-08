#include "Queue.hpp"

int main()
{
    QueueInSingleLinkedList queue;
    std::cout << "Initial queue\n";
    queue.printQueue();
    queue.printQueue(true);
    std::cout << "***************\n\n";
    queue.enqueue(10);
    std::cout << "After enqueuing 10\n";
    queue.printQueue();
    queue.printQueue(true);
    try
    {
        std::cout << "Front of the queue: " << queue.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    std::cout << "Queue size: " << queue.getSize() << '\n';
    std::cout << "***************\n\n";
    queue.enqueue(15);
    std::cout << "After enqueuing 15\n";
    queue.printQueue();
    queue.printQueue(true);
    try
    {
        std::cout << "Front of the queue: " << queue.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    std::cout << "Queue size: " << queue.getSize() << '\n';
    std::cout << "***************\n\n";

    try
    {
        std::cout << "Front of the queue: " << queue.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    std::cout << "***************\n\n";

    try
    {
        queue.dequeue();
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    std::cout << "After dequeuing\n";
    queue.printQueue();
    queue.printQueue(true);
    try
    {
        std::cout << "Front of the queue: " << queue.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    std::cout << "***************\n\n";
    std::cout << "Queue size: " << queue.getSize() << '\n';
    std::cout << "***************\n\n";
    try
    {
        queue.dequeue();
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    std::cout << "After dequeuing\n";
    queue.printQueue();
    queue.printQueue(true);
    try
    {
        std::cout << "Front of the queue: " << queue.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    std::cout << "***************\n\n";
    std::cout << "Queue size: " << queue.getSize() << '\n';
    std::cout << "***************\n\n";
    try
    {
        queue.dequeue();
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    std::cout << "After dequeuing\n";
    queue.printQueue();
    queue.printQueue(true);
    try
    {
        std::cout << "Front of the queue: " << queue.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    std::cout << "Queue size: " << queue.getSize() << '\n';
    std::cout << "***************\n\n";

    return 0;
}
