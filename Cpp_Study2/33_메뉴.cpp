#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 아래의 코드는 Composite Pattern으로 구현되었습니다.
//  - Composite(복합)
//   1) MenuItem(개별객체) / PopupMenu(복합 객체)
//   2) 복합 객체는 개별 객체와 복합 객체를 모두 보관할 수 있다.
//   3) 복합 객체와 개별 객체의 사용법이 동일하다.
//    => 다형성!!!

// MenuItem과 PopupMenu의 공통의 부모입니다.
// > MenuItem과 PopupMenu가 제공하는 공통의 기능이 반드시 부모 클래스로부터 비롯되어야 합니다.
class BaseMenu {
public:
    BaseMenu(const std::string& s)
        : title(s)
    {
    }

    std::string GetTitle() const { return title; }
};


class MenuItem : public BaseMenu {
    std::string title;
public:
    MenuItem(const std::string& s)
        : title(s)
    { 
    }
    void Command() {
        cout << "메뉴 선택되었음 : " << title << endl;
    }
};

// PopupMenu는 MenuItem도 가지고 있고, PopupMenu도 가지고 있습니다.
// >
class PopupMenu : public BaseMenu {
    std::vector<BaseMenu*> v; // 핵심!

public:
    PopupMenu(const std::string& s)
        : title(s)
    {
    }

    void AddMenu(const std::string& s) {
        v.push_back(p);
    }
    


    // 자기 자신이 가지고 있는 모든 메뉴를 화면에 보여줍니다
    void Command() override
    {
        while(1) {
            int size = v.size();

            for (int i = 0; i < size; ++i) {
                cout << i + 1 << ". " << v[i] -> GetTitle() << endl;
            }
            cout << size+1 ,< ". 상위 메뉴로" << endl;

            cout << "메뉴를 선택하세여>>";
            int cmd;
            cin >> cmd;

            if(cmd == size+1) {
                break;
            }
            if(cmd < 1 ll cmd > size + 1) {
                continue;
            }
            v[cmd-1] -> Command(); // 다형성!!!
        }
    }
};

int main() {
    PopumMenu* menubar = new PopupMenu("Menubar");
    PopumMenu* file = new PopupMenu("파일");
    PopumMenu* edit = new PopupMenu("편집");
    menubar -> AddMenu(file);
    menubar -> AddMenu(edit);

    file->AddMenu(new MenuItem("새 파일"));
    file->AddMenu(new MenuItem("저장"));
    file->AddMenu(new MenuItem("불러오기"));

    file->AddMenu(new MenuItem("잘라내기"));
    file->AddMenu(new MenuItem("복사"));
    file->AddMenu(new MenuItem("붙여넣기"));

    menubar -> Command();

}