#include<iostream>
using namespace std;

// 1) Default parameter 
//    함수에서 전달되는 인자가 없는 경우 기본값을 사용합니다.
//    > 기본값을 지정할 때, 반드시 뒤에서부터 지정해야 합니다.

// function을 선언과 구현으로 분리할 때는 선언부에만 기본값을 표기해야 합니다.
// 선언부와 구현부에 모든 디폴트값을 표기하면, 컴파일 오류가 발생합니다.
void foo(int a, int b, int c = 5, int d = 20) {
    cout << a << ", " << b << ", " << c << ", " << d << endl;
}
// void는 반환 자료형이 없다. 

int main() 
{
    foo(10, 20, 30, 40);
    foo(20, 30);
}


// C++ 에서는 파라미터의 타입이나 개수가 다르면,
// 동일한 이름의 함수를 여러개 만들 수 있습니다.
// => "함수 오버로딩" 이라고 부릅니다.
// => 컴파일러가 함수의 파라미터정보를 통해 이름을 생성합니다.
// => 파라미터의 개수와 타입이 다르면 다른이름이 생성됩니다.
// "네임 맹글링"

// 주의사항 
// - 반환 타입은 함수 이름에 영향을 미치지 않습니다. 
// > 파라미터가 동일하고 반환타입이 다른 함수는 오버로딩이 불가능합니다. 
// int foo() {};
// void foo() {};
// void goo(int a) {};
// void goo(int a, int b=100) {};

int square(int x) 
{
    printf("int\n");
    return x * x ;
}

double square(double x) 
{
    printf("double\n");
    return x * x;
}

long square(long l)
{
    printf("long \n");
    return l * l;
}

char square(char c)
{
    printf("char \n");
    return c * c; 
}

// 오버로딩 규칙
// 1) 정확한 타입을 찾습니다. 
//    square(42) -> square(int)

// 2) 상승 
//    square(int) -> square(char)

// 3) 호환 
//    square(char) -> square(long)
//    상승과 호환은 컴파일러 버전이 올라가버리면 소용이 없다!

// int main()
// {
//     square(42);
// }

// 매크로 함수 
// 문제점
// 1) 치환이기 때문에, 우선순위에 대한 주의가 필요하다. 
// 2) > 괄호를 통해서 매크로 함수의 우선순위 문제를 해결할 수 있습니다.

// #define SQUARE(x) ((x)*(x))

// int main()
// {
//     SQUARE(3);
//     SQUARE(3.14);

//     int x = 1;
//     SQUARE(++X);
// }

// int main()
// {
//     goo(10);
// }


// 함수 
// > 오버헤드가 있습니다. 
// - 함수를 호출하면, 함수 인자를 스택을 통해 전달하고, 해당하는 함수의 주소로 이동(점프) 합니다.
//   함수의 코드를 실행하고, 함수의 결과를 레지스터로 담아서 다시 복귀합니다. 

// C++은 함수를 호출하지 않고, 기계어 코드로 치환하는 문법을 제공합니다. 

// int add(int a, int b) {
//     return a + b;
// }


/*인라인 함수
장점 : 호출이 아니라 치환이므로, 속도가 빨라집니다.
단점 : 함수의 기계어가 큰 경우, 전체적인 실행파일의 크기가 늘어납니다.
       => 코드 블로우트 현상이 발생할 수 있습니다. 
line int add(int a, int b) {
    return a+b;  // resister를 이용해 연산을 수행하고 다시 복귀.
    // 그래서 인라인 함수는 복잡한 함수말고 요런 간단한 함수에서 주로 사용한다.
    // 인라인 함수는 C++에서 매우 중요한 문법(개념)이다.
    // 그래서 인라인 함수를 사용하면 무조건 적용이 되느냐?? 그건 아니다~ 컴파일러가 알아서 결정해줄거다..
}
*/

// CPU 
// > resister(레지스터) : 명령어를 실행하는데 필요한 변수 
// IP : Instruction Pounter 
//     현재 실행중인 명령어의 주소 
// sp : Stack Pointer
// BP : Base Pointer

int main()
{
    // int ret = add(10, 20);
    int ret = 10 + 20; // 위 코드보다 당연히 이게 빠름. 
    // why??? : 첫번째 ret은 함수를 거쳐서 계산을 하고 다시 반환하지만, 두번째 ret은 바로 계산하고 반환하기 때문이다.
    printf("%d\n", ret);
}