// 디자인 패턴(Design Pattern)
// => 1995년 디자인 패턴
//    : 에릭감마 외 3명(Gang of Four) => Gof

#include <iostream>
using namespace std;

class Point 
{
    int x, y;

public:
    // void set(Point* const this, int a, int b);
    void set(int a, int b) {
        x=a; // this -> x = a;
        y=b; // this -> y = b;
    }
    static void foo(int a) {
        // x = a;
        // 정적 멤버 함수는 객체 없이 호출 가능하다.
        // > 객체의 멤버 데이터에 접근이 불가능ㅎ다.
        // - this 가 전달되지 않습니다.
    }
};


int main() {
    Point p1, p2;
    p1.set(10, 20); // Point::set(&p1, 10, 20)
    p2.set(10, 20); // Point::set(&p2, 10, 20)

}