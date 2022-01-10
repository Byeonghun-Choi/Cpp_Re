#include<iostream>
using namespace std;

// 1. 자동차에 카메라를 연결하기 위해 지켜야 하는 규칙을 먼저 설계한다. (약속)
//    => 인터페이스 (프로토콜)
//    => 아래처럼 구현이 제공되지 않는, 순수 가상 함수로만 이루어진 클래스를 "인터페이스" 라고 한다.

// 인터페이스
// => 교체 가능하다.

#if 0
class BlackBoxCamera {
    public:
    virtual ~BlackBoxCamera() { }
    virtual void StartRecord() = 0;
    virtual void StopRecord() = 0;
};
#endif

sturuct BlackBoxCamera { // 인터페이스
    virtual ~BlackBoxCamera() { }

    virtual void StartRecord() = 0;
    virtual void StopRecord() = 0;

    virtual void NewFeature() {

    }
};

// 3. 카메라의 작성자는 반드시 BlackBoxCamera 의 인터페이스를 구현해야 합니다.
//  => BlackBoxCamera를 상속 받아서 만들어야 합니다.
class Camera {
public:
    void StartRecord() override {
        cout << "Start Record" << endl;        
    }
    void StopRecord() override {
        cout << "Stop Record" << endl;
    }
};

class HDCamera : public BlackBoxCamera {
public:
    void StartRecord() override { 
        cout << "[HD]Start Record" << endl;
    }
    void StopRecord() override {
        cout << "[HD]Stop Record" << endl;
    }
};

// Car 클래스는 Camera 타입에 강하게 결합되어 있습니다.
// => "강한 결합" : 어떤 클래스를 사용할 때, 구체적인 타입에 의존하는 것을 의미합니다.
// => 해결 방법 : 약한 결합


// 2. BlackBoxCamera를 이용하는 코드를 작성합니다.
class Car {
private:
    Camera* pCamera;

public:
    Car(HDCamera* p)
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