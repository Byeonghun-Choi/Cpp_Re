#include<iostream>
using namespace std;

// C/C++에서 가장 많이 사용하는 연산자 중에 하나인
// 증감 연산자를 재정의하는 것을 이해해야 한다.

class Integer {
    private:
    int value;

public:
    Integer(int n = 0) 
        : value(n)
        {

        }
    Integer& operator++() {
        ++value;
        return *this;
    }

    friend std::ostream& operator << (std::ostream& os, const Integer& i);
};

std::ostream& operator << (Std::ostream& os, const Integer& i) {
    return os << i.value << endl;
}

int main() {
    int n1;
    cout <<n1<<endl;

    Integer n2;
    // cout << n2 << endl;
    n2.Print();
}