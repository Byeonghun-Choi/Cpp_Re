#include<iostream>
using namespace std; 

// C++11에서는 레퍼런스라는 새로운 형태의 타입을 제공합니다. 
/*
int main()
{
    int n = 0;  // 이 순간 4byte의 메모리가 할당됩니다.
    int &r = n;  // 새로운 메모리를 할당하는 것이 아니라
                // 기존 메모리의 새로운 이름을 부여합니다.

    int &r2;  // 컴파일 오류
              // 레퍼런스 변수는 기존 변수의 별칭이므로, 반드시 초기값이 있어야 한다.

    r = 10;
    cout << n << endl;  // 10
}
*/

// 1) call by value 
// inc1 
//    x : 10 -> 11

//    -------------
//    main 
//       n: 10

void inc1(int x) {
    ++x;
}

// 2) call by reference (pointer)
// inc2 
//    x(0x100) : 10

// ------------------
// main 

void inc2(int *x) {
    ++(*x);
}
/*
int main()
{
    int n = 10;
    inc1(n);
    inc2(&n);
    inc3(n);

    cout << n << endl;
}
*/
void foo(int x[5]) {  // 배열의 이름이 decay 이기 때문에, int x[5] 이런 형식은 의미가 없다.
    printf("foo : sizeof(%ld)\n", sizeof(x));
}

void goo(int (&x)[5]) {
    printf("goo : sizeof(%ld) \n", sizeof(x));
} // ld? long double???

int main()
{
    int x[5];
    printf("sizeof(%ld)\n", sizeof(x));

    foo(x);
    goo(x);
}


/*코드는 일관성을 가지는게 중요하다. 
개발은 혼자하는게 아니다!@ 
ALM : Application Lifecycle Management
이슈관리, 코드관리, 소통 
코드관리 할 때 중요한 것 : 히스토리 관리 
git << */

struct User {
    std::string name;
    int age;
};

// 복사에 의한 오버헤드를 없앨 수 있습니다.
// => call by value 
//    : 함수를 통해서 전달받은 파라미터의 값을 변경하지 않습니다.
//      void printUser(User user)
//      문제점 : 구조체 등의 크기가 큰 타입이 전달될 경우, 복사에 의한 오버헤드가 있습니다.

// 해결
// => call by reference 
// => void printUser(User &user)
//    : 복사에 의한 오버헤드를 없앨 수 있습니다.
//      함수에서 파라미터의 값을 변경하지 않아야 합니다. 
//      const& 를 사용해야 합니다. 
// => coid printUser(const User &user)
void printUser(const User &user) {
    cout << user.name << ", " << user.age << endl;

    // user.age += 10  // compile error! 
}

void printUser(User &user) {
    cout << user.name << ", " << user.age << endl;
}

int main() 
{
    User user{"Tom", 42};
    printUser(user);
}