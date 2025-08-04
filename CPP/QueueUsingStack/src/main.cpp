#include "Queue.hpp"

#include <iostream>

int main() {
    QueueUsingStack qus;
    for (const int i : {1, 2}) {
        qus.enqueue(i);
    }
    for (auto i = 3; i > 0; --i) {
        auto opt = qus.dequeue();
        (opt.has_value()) ? std::cout << "Dequeued: " << opt.value() << '\n' : std::cout << "Empty queue\n";
    }
    return 0;
}
