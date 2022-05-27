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
/*
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
}*/


/* 탐색
1. Tree (이진 트리)
- 탐색 - O(log N)
- 정렬 - O(N)

2. HashTable => <unordered_map>
bucket을 무한정 만들 수 없으므로, 충돌 발생 위험이 있다.
C++에는 라이브러리가 내장되어 있다.
- 탐색 : O(1)
데이터가 저장되는 순서가 다르다.
=> QuickSort O(NlogN)

map => 키-값 쌍으로 이루어진 데이터
C++ / Java
C# / Swift - Dictionary 라고도 부른다.*/

#include<map>

int main()
{
    std::map <std::string, std::string> data;
    data["홍길동"] = "010-1234-5678";
    data["이순신"] = "010-2222-3333";

    std::cout << data["홍길동"] << std::endl;
}