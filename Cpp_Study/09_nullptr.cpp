#include<iostream>
using namespace std;
// C언어에서 0은 int 타입이지만, 컴파일러에 의해서 특별하게 처리됩니다. 

// NULL
// -> #define NULL (void *) 0
int main()
{
    int *p = 10;
    int *p = 0;  // 0은 정수이지만 포인터로 암묵적 형변환이 됩니다.

    int *p = nullptr;  // 이렇게 쓰는 것을 권장하고 있습니다.
    // int a = nullptr;  // error!
    // bool b = nullptr;  // 얘는 오류지만 
    bool b(nullptr);  // 직접 초기화시 nullptr을 bool의 암묵적 변환
}

// C++11에서는 포인터 0을 나타내는 nullptr을 제공합니다.