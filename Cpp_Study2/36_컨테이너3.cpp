
#include <iostream>
using namespace std;

// 2. Template 기반 컨테이너
//  장점 : 타입 안정성이 뛰어나고 객체뿐 아니라 표준 타입도 저장 가능하고, 꺼낼 때 캐스팅도 필요하지 않습니다.

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T a, Node* n)
        : data(a)
        , next(n)
    {
    }
};

template <typename T>
class Slist {
    Node<T> * head;

public:
    Slist()
        : head(nullptr)
    {
    }

    void push_front(T a) { head = new Node<T>(a, head); }
    const T& front() { return head -> data; }
};

int main()
{
    Slist<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);

    int n = s.front();
    cout << n << endl;
}