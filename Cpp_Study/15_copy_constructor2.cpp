#include<iostream>
using namespace std;

// 얕은 복사란 값을 복사하는 것이 아닌, 값을 가리키는 포인터를 복사하는 것.
class Point{
    int x, y;

public:
    Point() { cout << "Point()" << endl; }
    ~Point() { cout << "~Point()" << endl; }
    Point(const Point &rhs) {
        cout << "Point(const Point&)" << endl;
    }
};

/*
int main()
{
    // 복사 생성자는 언제 호출되는가?
    // 1. 객체를 만들 때 자신과 동일한 타입으로 초기화되는 경우 호출.
    // Point p1; // Point()
    // Point p2(p1);  // Point(const Point&)

    // Point p3 = p1;  // Point(const Point&)

    // Point p4{ p1 };  // Point(const Point&)
    // Point p5 = { p1 };  // Point(const Point&)
    
}*/


// 1. 함수 호출시 인자를 call by value로 전달할 때

// void foo(Point p) {  // Point(const Point&)
//     ~Point() - foo 함수가 끝날때 p 객체가 파괴되면서 호출된다.
// }


// void foo(const Point &p) {

// }


// int main()
// {
//     Point p1;  // Point()
//     foo(p1);

//     ~Point() - p1 객체가 파괴되면서 호출됩니다.
// }


// void foo(Point p)
// 1) 복사본을 위한 추가적인 메모리 사용
// 2) 복사 생성자, 소멸자 함수 호출에 따른 오버헤드가 있습니다. 
// 3) 함수가 객체를 값으로 반환할 때,
Point p;
Point foo() {  // foo가 끝나면 Point foo() 영역 자체가 사라져버린다.
    Point p;
    return p;
}

int main()
{
    foo();
    // Point ret = foo()
    // 리턴 값으로 돌아온 객체는 p가 아니라 반환용 임시객체가 전달됩니다.
    // 반환용 임시객체는 함수 호출문장 끝에서 파괴됩니다.
    printf("end main\n");
}