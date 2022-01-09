#include <iostream>

// vscode에서 파일 돌릴떄
// g++ 1_namespace2.cpp 
// 출력 : ./a.out

/*
1. 전체 이름을 사용하는 방법
   : 이름공간과 함수의 이름을 사용한 방법
   ex) std::cout; std::endl;

int main() {
    std::cout << "Hello, cpp" << std::endl;
}
*/

/*
2. using 선언을 사용하는 방법.
using std::cout;
using std::endl;

int main() {
    std::cout << "Hello, cpp" << std::endl;
}
*/

/*
3. using 지시어 (directive) 예제 목적으로만 사용.
#include <algorithm>
using namespace std; // std를 open 해버리면 이름충돌의 위험성이 있다.
using std::cout;
using std::endl;
*/
// 개발자들은 std::를 가장 선호하기 때문에, 이에 맞추자.

// 그럼 이름충돌이 나는 경우는 어떤 경우일까???
int count;
std::count; // 여기랑 42번째 줄이 오류가 발생.
int main() {
    count = 10;
    std::cout << "Hello, cpp" << std::endl;
         << "Hello, cpp" << std::endl;
}
