#include<iostream>
using namespace std;
// 아이템 상태에 따른 동작의 변화
// 방법 3. 변하는 것을 가상함수로 만듭니다
//     => Item에 따라 동작은 변한다.
//    => Template Method Pattern

class Character {
    
    int item;

public:
    int gold;
    void Run() { cout<< "Slow Run" << endl; }
    void Attack() { cout << "Attack" << endl; }
};

// 아이템의 획득에 따라 동작을 변경하기 위해, 상속을 사용합니다.
class FastRunCharacter : public Character {
    public:
    void Run() override { cout << "Slow Run" << endl;}
};



int main() {
    Character* current;

    Character c;
    current = &c;
    current->Run();

    FastRunCharacter fc;
    current = &fc;
    cout << current->gold << endl;

    SlowRunCharacter &c;
    current = &sc;
    current -> Run();
}