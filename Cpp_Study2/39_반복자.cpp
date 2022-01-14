// 38_반복자
// : Iterator Pattern
// > 중요합니다.
#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& a, Node* n)
        : data(a)
        , next(n)
    {
    }
};

template <typename T>
class SlistIterator {
    Node<T> current;

public:
    SlistIterator(Node<T>* p = nullptr)
        : current(p)
    {
    }

    inline SlistIterator& operator++()
    {
        current = current->next;
        return *this;
    }

    inline T& operator*() { return current->data; }

    inline bool operator==(const SlistIterator& t)
    {
        return current == t.current;
    }

    inline bool operator!=(const SlistIterator& t)
    {
        return current != t.current;
    }
};

template <typename T>
class Slist {
    Node<T>* head;

public:
    Slist()
        : head(nullptr)
    {
    }

    void push_front(const T& a) { head = new Node<T>(a, head); }

    const T& front() { return head->data; }
};

int main()
{
    int x[5] = { 1, 2, 3, 4, 5 };
    int* p = x;
    int* p2 = x + 1;

    ++p;
    if (p == p2) {
        cout << "같은 위치" << endl;
    }

    cout << *p << endl;
}