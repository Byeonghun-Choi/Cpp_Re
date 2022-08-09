#include<iostream>
using namespace std; 

struct Point 
{
    int x, y;
};

/*
int main()
{
    int n1 = 42; // 할당 연산, 복사 초기화 
    int n2(42);  // C++ 초기화 문법, 굳이 사용하지는 않는다. 직접 초기화
    // 일반 변수는 '=' / '()' 로 초기화합니다.
    cout << n1 << ", " << n2 << endl;

    // () 초기화 : 직접 초기화 (direct initialization)
    // = 초기화 : 복사 초기화 (copy initialization)

    // 2. 배열과 구조체 초기화 방법.
    Point p = {10, 20};
    int x[3] = {10, 20, 30}; // 연속된 메모리가 초기화된 상태
}
*/ 

// C++11 - uniform initialization / C++ 의 진입장벽을 낮추겠다! 가 목표
// > 일관된 방법을 통해 변수를 초기화할 수 있다.
int main() 
{
    int n3 = 3.14;
    cout << n3 << endl;

    int n4[3.14];
    // Data 손실이 발생하는 잘못된 초기화에 대해서 컴파일 오류가 발생합니다.
    char c1 = 300; // char는 255까지만 받는다. 즉 overflow 문제가 발생
    char c2{300};

    // = (등호) : Copy initialization
    int n1 = {0};
    int x[3] = {1, 2, 3};
    Point p1 = {10, 20};

    // Direct initialization 신기하게 개발자들이 선호하는 방법은 직접이다.
    // C++ 자체는 OOO도 중요하지만 성능도 매우 중요하다. 문법의 간결함도 매우 중요.
    int n2{0};
    int x[3] {1, 2, 3};
    Point p2{10, 20};
}