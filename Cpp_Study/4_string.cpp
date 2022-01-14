#include<iostream>
using namespace std;

// 참고로 string은 헤더파일로 주로 사용한다
// string 헤더파일을 왜 사용하나??
// : 기존 C언어에서 문자열 처리를 하는 것은 상당히 골치 아팠다.
//   이것을 해결하기 위해서 C++ 에서는 class로 문자열을 감싸고 
//   public 을 통해 쉽게 사용할 수 있도록 정의하고 만들었다.

// string 말그대로 문자열을 다룬다

// string s.assign() : string s("Enco")과 동일한 기능

// string str : 문자열 생성
// cin >> str;  :  공백(space) 이전까지의 문자열을 입력받는다.
// getline(cin, str); : '\n' 이전까지의 문자열, 즉 한 줄을 통째로 입력받는다. (공백 포함)
// getline(cin, str, 'a') : 'a' 문자 이전까지의 문자열을 입력받는다. 
// getline(cin, str, '\n') == getline(cin, str)
// cout << str;        // 문자열을 출력한다.
// string str ("Enco") : str 변수를 "Enco"로 초기화.
// string str = "Enco" : 마찬가지로 str 변수를 "Enco"로 초기화.

#include <string>
int main() 
{
    std::string s1 = "hello";
    std::string s2 = "hello";

    if (s1 == s2) { // 주소를 비교
        cout << "동일한 문자열 입니다." << endl;
    } // string 헤더파일에서는 printf, scanf 사용이 불가하다.

    std::string s3 = s2; // strcpy
    cout << s1 << ", " << s2 << ", " << s3 << endl;
}