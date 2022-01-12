#include <iostream>
#include <string>
using namespace std;

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
// Windows - getch(비표준 함수)

// 에코 없이 입력하면 바로 결과가 나오는 처리 방식
int getch(void)
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
//--------
// 공통성과 가변성 분리 방법 2번째, 
// - 변하는 것을 다른 클래스로 뽑아냅니다.
// => 교체 가능한 인터페이스 기반 클래스로 뽑아냅니다.
//  : Strategy Pattern (전략 패턴)
// 1) 실행 시간에 정책을 변경하는 것이 가능합니다.
//    -lineEdit.SetValidator(...)
// 2) Validator의 정책을 다른 클래스에서도 재사용 가능합니다.

// validation 정책에 관한 인터페이스를 설계합니다.
struct Validator {
    virtual -Validator() { }
    virtual bool validate {const std::string& s, char c}
        = 0;
    virtual bool IsComplete(const std::string& s) = 0;
};

class LineEdit {
    std::string data;

    // -------
    Validator* pValidator;

public:
    LineEdit()
        : pValidator(nullptr)
        {
        }
    void SetValidator(Validator* p) { pValidator = p; }
    // ---------

    std::string GetData()
    {
        data.clear();

        while (1) {
            // char c = getchar();
            char c = getch();

            if (c == '\n' && (pValidator == nullptr || pValidator->IsComplete(data)))
                break;

            if (pValidator == nullptr || pValidator->Validate(data, c)) {
                data.push_back(c);
                cout << c;
            }
        }

        cout << endl;
        return data;
    }
};

// 새로운 정책의 LineEdit가 필요하면, 
// 정책 클래스를 Validator의 인터페이스를 기반으로 만들어주면 됩니다.

class LimitDigitValidator : public Validator {
    int limit;
public:
    LimitDigitValidator(int n) 
        : limit(n)
    {
    }

    bool Validator(const std::String& s, char c) override {
        return s.size() < limit && isdigit(c);
    }

    bool IsComplete(const std::string& s) override {
        return s.size() == limit;
    }
};

int main()
{
    LineEdit edit;
    while (1) {
        string s = edit.GetData();
        cout << "out: " << s << endl;
    }
}