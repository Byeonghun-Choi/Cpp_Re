#include<iostream>
using namespace std;

int square(int a) { return a * a; }
double square(double a) { return a * a; }
// return 타입과 parameter 타입을 제외하면 구현이 완전히 동일하다.
// => 사용자가 템플릿을 제공하면 컴파일러가 코드를 컴파일할 때, 어떤 타입의 함수가 필요한지
//    조사해서 실제 함수를 생성해줍니다. 

// => C++ Template
//    Java, Kotlin, C#, Swift ...
//    : Generics 

// template <typename T> // 요게 템플릿, C언어 제외하고는 대부분 가지고 있다.
// * template <class T> 와 같다.
// T square(T a) { return a * a; }
// template 대신 class를 써도 된다. 

// int main() {
//     cout << square(3) << endl;
//     cout << square(3.14) << enndl;
// }

int gcd(int a, int b) {
    return b != 0 ? gcd(b, a % b) : a;
}

// gcd 함수를 double 에 대해서 사용할 수 없도록 하고 싶다.
// 1) 의도적으로 함수의 선언부만 제공합니다. 
// => 링킹 오류를 통해 실행 파일 생성이 금지됩니다. 
// => 링킹 오류는 분석이 어렵습니다.
double gcd(double a, double b) // 핵심 : 선언만 하는 것! 
// 그럼 실수로 들어온 함수가 double 로 매치되어 들어왔을 때, 비어있는 함수를 제공함으로써 컴파일을 막는다.

// 2) C++ 11 delete function 
//    => 함수를 삭제하는 방법
//    => 컴파일 오류가 발생합니다.

// 쉽게 사용할 수 있게 만드는 것도 중요한데, 잘못 사용하기 어렵게 만드는 것도 중요하다.

double gcd(double a, double b) = delete;  // delete 배열의 형태로 받아야 삭제가 원활하게 진행될 수 있다.



// int main() {
//     cout << gcd(2, 10) << endl; // int gcd로 들어감.
//     cout << gcd(2.2, 4.3) << endl;  // double gcd로 들어감. 물론 비어있기 때문에 같이 나오지는 않는다.
//     // double이 int 로 암묵적인 형변환되서 동작합니다.
//     // => 동작하면 안되는 코드입니다.
// }


// -> 여기서 compile이 동작한다.
// main.cpp -> main.o  => main.cpp + main.o 
void foo();   // 그래서 위에 foo를 미리 선언해주면 main.cpp가 읽을 수 있다.
int main() {
    foo();  // 여긴 컴파일 오류가 날거다. why?? foo가 어디있는데??
}


// 면접에선 이런걸 물어본다.
// 기술면접 : static 키워드가 언제 사용되냐??
// 지역변수 앞, 전역변수 앞
// 지역변수 : 내부 정착 변수 
// static 지역변수 : 전역변수 
// extern 키워드가 생략되어있다.


// 함수 포인터
// => 함수의 주소를 참조하는 포인터이다.
// => 함수 포인터를 통해 함수를 호출할 수 있다.

// 함수의 타입은 함수의 파라미터와 반환 타입에 의해 결정된다.
//  => 함수의 파라미터와 반환 타입이 동일하면 동일한 타입이다.

auto sub(int a, int b) -> int {
    return a - b;
}

auto add(int a, int b) -> int {
    return a + b;
}


// C++ 11 - Trailing return type 
//  => 함수를 만드는 새로운 문법을 제공합니다.
auto sub1 (int a, int b) -> int {
    return a - b;
}

auto foo2() -> int (*)(int a, int b) {
    return &add;
}

using FP = int (*)(int a, int b);

void foo() {
    return &add;
}

FP foo() {
    return &add;
}

int (*foo()) (int a, int b) {
    return &add; 
}

int main()
{
    int a;
    add(10, 20);

    int *p = &a;  // 54~56의 방법을 권장하심.
    // add의 타입은 => int(int a, int b)
    int (*p2) (int a, int b) = &add; 

    p2 = &sub;  // 디케이(Decay) : 함수의 이름은 포인터 타입으로 해석된다.
    // p2는 오른쪽이 더 우선순위가 높기 때문에 괄호를 통해 우선순위를 바꿔준다.
    cout << (*p2) (10, 20) << endl;
}

int main() 
{
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(int i = 0; i < 10; i++) { cout << x[i] << endl; }
    // C++11 - ranged for 
    for (int n : x) 
        cout << n << endl;
}