#include "Queue.hpp"

template <typename T>
void printQueue(const QueueInSingleLinkedList<T> &queue)
{
    std::cout << "Queue:\n";
    queue.printQueue();
    std::cout << "Queue to string:\n";
    queue.printQueue(true);
    std::cout << "Queue size: " << queue.getSize() << '\n';
}

int main()
{
    QueueInSingleLinkedList<double> queue;
    std::cout << "Initial queue\n";
    printQueue(queue);
    std::cout << "***************\n";
    std::cout << "Enqueuing 10.0\n";
    queue.enqueue(10.0);
    printQueue(queue);
    std::cout << "***************\n";
    try
    {
        std::cout << "Front of the queue: " << queue.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    std::cout << "Enqueuing 15.5\n";
    queue.enqueue(15.5);
    printQueue(queue);
    std::cout << "***************\n";
    try
    {
        std::cout << "Front of the queue: " << queue.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }

    std::cout << "Dequeuing...\n";
    try
    {
        queue.dequeue();
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    printQueue(queue);
    std::cout << "***************\n";
    try
    {
        std::cout << "Front of the queue: " << queue.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    std::cout << "Dequeuing...\n";    
    try
    {
        queue.dequeue();
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    printQueue(queue);
    std::cout << "***************\n";
    try
    {
        std::cout << "Front of the queue: " << queue.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    std::cout << "Dequeuing...\n";
    try
    {
        queue.dequeue();
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    printQueue(queue);
    std::cout << "***************\n";
    try
    {
        std::cout << "Front of the queue: " << queue.peek() << '\n';
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }

    return 0;
}
