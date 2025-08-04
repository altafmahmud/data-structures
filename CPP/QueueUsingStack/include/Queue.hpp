/* Imitate queue operation using a single stack */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stack>
#include <optional>

class QueueUsingStack {
public:
    QueueUsingStack() = default;
    ~QueueUsingStack() = default;

    void enqueue(const int val);
    std::optional<int> dequeue();

private:
    std::stack<int> stck;
};

#endif // QUEUE_HPP
