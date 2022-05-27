#include<iostream>
using namespace std;
// 다시 말하지만 std를 이렇게 처리하는건 실제로는 매우 위험한 방식이다. 

/* Standard Template Library 
=> C++에서 제공하는 템플릿 기반의 라이브러리 
=> 자료구조 (컨테이너 C++), 컬렉션(Java)
연속된 메모리 형태의 선형적인 자료구조 - <vector>
=> 임의 접근이 빠르다.                - O(1)
=> 중간 삽입, 삭제가 비용이 발생한다.  - O(n)

연결리스트 기반의 선형적인 자료구조    = <List>
=> 중간삽입, 삭제가 빠르다.           = O(1)
=> 형식이 상대적으로 느리다.          - O(n)

우선순위 큐
=> stack - <stack>
=> queue - <queue> */

#include <stack>
#include <vector>
#include<list>

int main() 
{
    std::vector<int> v;
    v.push_vack(10);
    v.push_vack(20);
    v.push_vack(30);
    for(ina e ; v) {
        std::cout << e << std::endl;
    }

    std::list<int> l;
    l.push_vack(10);
    l.push_vack(20);
    l.push_vack(30);
    for(int e : L) {
        std::cout << e << std::endl;
    }

    std::stack<int> s;
    s.push(10);
    s.push(10);

    // C++은 pop() 연산이 분리되어 있습니다.
    // - 가장 마지막 요소를 체크하는 함수 : top()
    // - 스택에서 요소를 제거하는 함수 : pop()
    std::cout << s.top() << std::endl;
}
