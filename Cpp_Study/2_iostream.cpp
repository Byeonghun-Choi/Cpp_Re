// C++ 표준 입출력
// 1. C 언어에서 표준 입출력을 위해 대표적으로 사용되는 함수
//   : printf, scanf
/*
ex)
#include<stdio.h>
int main() {
    int n = 0;
    scanf("%d", &n); // call by reference : &, 주소값을 전달해주는
    printf("out : %d \n", n);
}
*/

// C++ 에서 제공되는 표준 입출력

#include <iostream> // C언어에서 사용하던 printf, scanf 도 탑재
using namespace std;
/*
int main() {
    int n =0;
    cin >> n;
    // scanf("%d", &n);
    // 1. 정수 타입을 지정할 필요가 없다. : 함수 오버로딩
    // 2. 주소를 보내지 않아도, 값이 변경된다. 포인터가 아닌 레퍼런스로 되어있다.
    // 3. std::cout, std::cin 정체는 무엇인가??
    // 4. std::endl 의 정체는 무엇인가?

    cout << "out: " << n;
    cout << std::endl;
}
*/

#include <iomanip>
int main() {
    int n = 42;
    std::cout << n << std::endl;
    cout << hex << n << endl;
    cout << uppercase << n << endl;

    cout << setw(4) << n << endl;
    cout << setw(4) << setfill('0') << n << endl; 
    cout << oct << n << endl;
    cout << dec << n << endl;
    // 한번 사용하면, 다시 변경하기까지 상태가 유지된다.
}

// Dev_Yoon : 문제를 해결하는 것도 중요하지만, 의도도 중요하다. 개발자는 혼자 일하지 않는다.
// 이래서 중요한 것이 표준라이브러리 해석. (의도를 명확히 알기 쉽게 표현해야 라이브러리를 공개해도 사람들이 알아보기 쉽다.)
