// : 초기화 리스트
#include<iostream>
using namespace std;

// 초기화와 대입의 개념을 이해하는 것이 중요하다.

class Point { // 선언부의 순서가 가장 먼저 수행된다.
    int x, y;
    const int c;
    int &ra;

public:
    // 아래처럼 사용하는 것은 대입입니다.
    /*Point(int a, int b) {
        // 대입의 형태로 동작합니다.
        x=a;
        y=b;
    }*/

    // 초기화 리스트 : 멤버 Data의 값을 초기화하는 문법입니다.
    Point(int a, int b) : x(a), y(b), c(42), ra(a) {
        // c = 10;  - 상수는 반드시 초기화되어야 합니다. - 초기화 리스트를 사용해야 합니다.
        // ra = a;
    }
};

int main() 
{
    int a = 10;
    int b;
    b = 10;
}