#include "Queue.hpp"

void QueueUsingStack::enqueue(const int val) {
    stck.push(val);
}

std::optional<int> QueueUsingStack::dequeue() {
    const auto cur_size = stck.size();
    if (cur_size == 0) {
        return std::nullopt;
    }
    const auto v = stck.top();
    stck.pop();
    if (cur_size == 1) {
        return std::optional<int>(v);
    }
    auto opt = dequeue();
    if (opt.has_value()) {
        enqueue(v);
    }
    return opt;
}
