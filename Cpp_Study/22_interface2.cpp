#include<iostream>
using namespace std;

class Camera {
public:
    void StartRecord() {
        cout << "Start Record" << endl;        
    }
    void StopRecord() {
        cout << "Stop Record" << endl;
    }
};

class HDCamera {
public:
    void StartRecord() {
        cout << "[HD]Start Record" << endl;
    }
    void StopRecord() {
        cout << "[HD]Stop Record" << endl;
    }
};

// Car 클래스는 Camera 타입에 강하게 결합되어 있습니다.
// => "강한 결합" : 어떤 클래스를 사용할 때, 구체적인 타입에 의존하는 것을 의미합니다.
// => 해결 방법 : 약한 결합
// 약한결합에 관한건 interface3에 이어서 만들겠다.

class Car { // 자동차 클래스가 카메라 객체에 강하게 의존하고 있다.
private:
    Camera* pCamera;

public:
    Car(HDCamera* p) // 생성자를 통해서 전달받는 이 형태가 중요하다.
        : pCamera(p)
    {
    }

    void Start() {
        // ...
        pCamera -> StartRecord();
    }
    void Stop() {
        // ...
        pCamera -> StopRecord();
    }
};


// OCP : 개방 폐쇄 원칙(Open Close Principle)
// - 코드는 수정에는 닫혀 있고, 확장에는 열려 있어야 한다.
// : 새로운 기능이 추가되어도, 기존 코드는 수정하면 안된다.

int main() {
    Camera cam;
    Car car(&cam);

    car.Start();
    car.Stop();
}