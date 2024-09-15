#include <iostream>

class StackInSingleLinkedList {
private:

public:
    StackInSingleLinkedList();
    StackInSingleLinkedList(const StackInSingleLinkedList&) = delete;
    ~StackInSingleLinkedList();

    friend std::ostream& operator<<(std::ostream&, const StackInSingleLinkedList&);
};

inline std::ostream& operator<<(std::ostream& os, const StackInSingleLinkedList& stackInSinglelinkedList)
{
    return os;
}
