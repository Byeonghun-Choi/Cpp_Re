// 객체지향 프로그래밍 (Object Oriented Programming)
#include<iostream>
using namespace std;

// 복소수 2 개의 합을 구하는 함수를 만들어 봅시다. 
/*
add(int ar, int ai, int br, int bi) {
    int sum_r = ar + br;
    int sum_i = ai + bi;

    return ...
} */
/*
1. outparameter
int *sr, int *si - out parameter 
                  : 결과를 전달받기 위한 파라미터

요 부분은 복잡도를 증가시키기 때문에 잘 사용하지 않는다.

void add(int ar, int ai, int br, int bi, int *sr, int *si) {
    *sr = ar + br;
    *si = ai + bi;
}

int main()
{
    int ar = 1, ai = 1;
    int br = 2, bi = 2;

    int sr = 0, si = 0;
    add(ar, ai, br, bi, &sr, &si);
}
*/

// 2. 복소수 타입을 도입합니다.
// > 구조체(Complex)를 사용합니다.

// struct Complex {
//     int re; 
//     int im;
// };

// 객체지향 프로그램의 핵심 
// : 모델링
// - 프로그램에 필요한 타입을 먼저 설계하고 프로그램을 만들자.

// Complex Add(const Complex &c1, const Complex &c2) {
//     Complex result = {c1.re + c2.re, c1.im + c2.im};
//     return result; 
// }

// int main()
// {
//     Complex c1 = {1, 1};
//     Complex c2 = {2, 2};

//     Complex result = Add(c1, c2); 
// }

/* stack을 만들어봅시다.
- 우선순위 큐 
: 스택 -LIFO 규칙(Last In First Out) - 후입선출
    큐 - FIFO(First In First Out) 선입선출 
    1. 전역변수 / 함수를 이용한 스택

    int buff[10];
    int idx = 0;
*/
/*
//push
void push(int v) {
    buff[idx++] = v;
}

// pop
int pop() {
    return buff[--idx];
}

int main() 
{
    push(10);
    push(20);

    cout << pop() << endl; 
    cout << pop() << endl;
}
*/

// 2. Stack 타입을 설계해봅시다. 
/*
struct Stack {
    int buff[10];
    int idx;
};

void push(Stack *s, int v) {
    s-> buff[(s->idx)++] = v;
}

int pop(Stack *s) {
    return s -> buff[--(s->idx)];
}

Stack s1;
int main()
{
    Stack s2; 

    // 초기화가 필요합니다.
    s1.idx = 0;
    s2.idx = 0;

    push(&s1, 10);
    push(&s2, );

    cout << pop(&s1) << endl;
    cout << pop(&s2) << endl;
}*/
/*
3. 상태를 나타내는 데이터와 상태를 조작하는 함수를 묶자.
4. 구조체 내부의 데이터를 외부에서 함부로 조작할 수 없도록 
    정보 은닉이 필요합니다.
    => 접근 지정자
    구조체는 접근지정자를 사용하지 않을 경우, 
    기본적으로 public이 된다. 
    => class 
    기본 접근지정이 private입니다.
5. 생성자 함수를 도입합니다.
    생성자(Constructor)
    - 함수 이름이 클래스 이름과 동일하고, 반환 타입을 표기하지 않습니다. 
6. 사용자가 스택의 크기를 결정할 수 있도록 합니다.
>  생성자는 인자를 가져도 되고, 인자를 가지지 않아도 됩니다. 
   생성자는 오버로딩이 가능합니다.
7. 더이상 객체를 사용하지 않을 때, 
- 객체가 파괴되는 시점에 호출되는 함수가 있습니다.
> 소멸자(Destructor)
- 함수 이름은 -클래스이름()입니다.
- 반환타입을 표기하지 않습니다.
- 인자를 가질 수 없습니다.
- 객체가 파괴되는 시점에 수행됩니다. */

/*
class Stack {
private:  // 구조체 내부에서만 수정가능
    // 멤버 변수(Data)
    int buff[10];
    int idx;  // 구조체 외부에서도 접근 가능. (꼬리가 길다)

public:
    Stack() {
        cout << "Stack()" << endl;
        idx=0;
    }
    // 멤버 함수
    // - 멤버 데이터에 접근하는 함수
    // > 명시적인 함수 인자로 Stack*을 받을 필요가 없습니다.
};

void int() {
    idx=0;
}

void push(int v) {
    buff[idx++] = v;
}

int pop() {
    return buff[--idx];
}

Stack s1;
int main()
{
    Stack s2;

    // 초기화가 필요합니다.
    // s1.idx = 0;
    s1.init();
    // s2.idx = 0;
    s2.init();

    // push(&s1, 10);
    s1.push(10);
    // push(&s2, 10);
    s2.push(20);

    cout << s1.pop() << endl;
    cout << s2.pop() << endl;
} */

class Stack {
private:
    int buff[10];
    int idx;

public:
    // Stack s1;
    Stack() {
        cout << "Stack()" << endl;
        idx=0;
    }

    // Stack s2 {10}
    Stack(int s2) {
        idx=0;
        buff = new int[s2];  // 사용자가 전달한 크기만큼 buff를 할당
    }

    void push(int v) {
        buff[idx++] = v;
    }

    int pop() {
        return buff[--idx];
    }
};

Stack s1;
int main()
{
    Stack s2(100);
    Stack s3(300);

    s1.push(10);
    s2.push(20);

    cout << s1.pop() << endl;
    cout << s2.pop() << endl;
}