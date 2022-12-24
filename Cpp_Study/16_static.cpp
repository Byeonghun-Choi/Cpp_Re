#include<iostream>
using namespace std; 

// 멤버 데이터 변수는 공유되지 않는다. 
// => 인스턴스 변수

// Car 객체가 총 몇개 생성되었는지 확인하고 싶다.
// => 해결 방법 
//    - 정적 멤버 데이터 변수

// int cnt = 0;
// 문제점 : 누구나 cnt에 접근해서 값을 변경할 수 있다.

class Car {
    int color;
    // Car 클래스 객체가 공유되는 데이터 변수
    static int cnt;

public:
    // Car 클래스 객체가 
    // static int cnt;
    static int getCount() {
        return cnt;
    }
    Car() {
        ++cnt;
    }
    ~Car() {
        --cnt;
    }
};

// Car.cpp
// int Car::cnt = 0;
// 1. 정적 멤버 데이터 변수는 반드시 클래스 외부에 선언해야 합니다. 
// 2. 정적 멤버 데이터 변수는 객체를 만들지 않아도 메모리에 존재한다. 
// => 전역변수의 수명과 동일
// 3. 정적 멤버 데이터 변수는 객체의 크기에 포함되지 않습니다.
// 4. 정적 멤버 데이터 변수의 접근방법 2가지
//     1) Car::cnt => 권장
//     2) Car c;
//         c.cnt;

struct User {
    int a;
    int b;
};

int main() {
    cout << sizeof(User) << endl;
    cout << sizeof(Car) << endl;

    cout << Car::getCount() << endl;

    Car c1, c2;
    // cout << Car::cnt << endl;  // ?
    cout << c1.getCount() << endl;
}

/*
정리 
1. 정적 멤버 데이터
- 모든 객체가 공유하는 멤버 데이터, 객체를 생성하지 않아도 메모리 존재. 
  전역변수와 달리 접근 지정자를 사용할 수 있고, 클래스 안에 포함되기 때문에, 
  관련된 데이터를 묶어서 관리 가능

2. 정적 멤버 함수
- 객체 없이 호출할 수 있는 멤버 함수이다.
  객체 없이 호출되므로 일반 함수와 유사하지만, 접근지정자를 사용할 수 있고, 특정 타입과 관련된 함수를 묶어서 관리할 수 있다.
*/