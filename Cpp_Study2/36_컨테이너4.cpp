
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
class SlistImpl {
    Node<T> * head;

public:
    SlistImpl()
        : head(nullptr)
    {
    }

    void push_front(void* a) { head = new Node(a, head); }
    void* front() { return head -> data; }
};

// SListImpl을 직접 사용할 경우, 캐스팅에 대한 코드가 불편합니다.
// 사용자가 편리하게 사용할 수 있도록 Template으로 자식클래스를 제공합니다.
// => Thin Template
// => inline을 사용할 경우, 치환되는 함수에 대해서 코드 메모리에 존재하지 않습니다.
// => SListImpl의 구현을 물려 받지만, 인터페이스는 물려받지 않아야 합니다.

template <typename T>
class Slist : private SlistImpl {
public:
    void push_front(const T& a) {
        // &a => const T* => const_cast => T* => void*

        SlistImpl::push_front(const_cast<T*>(&a));
    }

    inline T& front() {
        // void* => static_cast => T* => * => T&
        return *(static_cast<T*> (SlistImpl::front()))
    }
};


int main()
{
    Slist s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);

    int n = s.front();
    cout << n << endl;
}