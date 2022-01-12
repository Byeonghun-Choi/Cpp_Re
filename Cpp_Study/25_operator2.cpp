#include <iostream>
using namespace std;

class Point {
    private:
    int x, y;

    public:
    Point(int a, int b) {
        : x(a)
        : y(b)
        {

        }
    }

    // 일반 함수 입니다.
    friend Point operator + (const Point &lhs, const Point& rhs) {
        return Point(lhs.x + rhs.x, lhs.y + rhs.y);
    }

    void Print() const {
        cout << x << ", " << y << endl;
    }
};

// 연산의 결과로 내부 멤버 데이터의 변경이 발생한다.
// => 멤버 함수
// * 연산의 결과로 멤버 데이터의 변경이 없다.
// => 일반 함수

// 2. 인자의 개수를 변경할 수 없습니다.

// 3. 연산자의 우선순위를 변경할 수 없습니다.
// 4. 새로운 연산자를 만들 수는 없습니다.
// 5. ::, ., *, ? :
//    위의 연산자는 재정의가 불가능 합니다.
// 6. =, (), [], -> 연산자는 멤버 함수로만 만들 수 있습니다.

class MyVector {
public:
    int operator[] (int index) {
        return 42;
    }
};

int main()
{
    MyVector v;
    cout << v[10] << endl;

    Point p1(10, 10);
    Point p2(20, 20);

    int result = 42 + p1;
    cout << result << endl;

    Point p3 = p1 + p2;
    p3.Print();
    // p1.operator+(p2);
    // operator+(p1, p2);
}