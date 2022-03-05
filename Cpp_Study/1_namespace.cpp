#include <iostream>
#include <foo.h>
#include <goo.h>
using namespace std;

// Why use the "namespace" ???
// 1) 이름 충돌을 막기위해서.
//    그럼 충돌은 왜 일어나는데?
// : 두개 이상의 식별자(변수, 함수, 클래스명 등)가 있을때, 컴파일러가 모호함을 해결하기 위해 오류를 일으키는 것.
// 프로그램이 점점 더 커지면 식별자의 수가 증가하기 때문에, 이름 충돌이 일어날 확률이 커진다.

// 1 EX)
// int main() {
//     std::cout << doSomething(4, 3); // 참고로 우리는 std:: 를 반드시 사용해줘야 한다. 단지 예제를 공부할때만 namespace std; 를 사용하자.
//     // doSomething 은 헤더파일 foo랑 goo에 넣어놨다. 
//     return 0;
// }

// 참고로, std::cout 에 붙어있는 :: 는 범위 지정연산자이다.
// 1) class, 2) namespace
// a::Print() 하면 a 영역에 있는 Print() 를 호출한다는 뜻이다. 
namespace Audio {
    void init() { std::cout << "Audio::init" << std::endl; }
}
namespace Video {
    void init() { std::cout << "Video::init" << std::endl; }
}

void init() {
    std::cout << "Global init" << std::endl;
}

int main() {
    Audio::init(); // Audio 영역에 있는 init을 호출하란 뜻.
    Vidoe::init(); // Video 영역에 있는 init을 호출하란 뜻.

    init();
}