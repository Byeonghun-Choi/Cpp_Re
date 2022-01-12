#include<iostream>
using namespace std;

// 스레드 클래스를 설계해봅시다.
// g++ 27_thiscall4.cpp -lpthread

#if 0
#include<pthread.h>

int main() {
    pthread_t thread;
    pthread_create(&thread, nullptr, &foo, nullptr);

    pthread_join(thread, nullptr);

    cout << "main end" << endl;
}
#endif


class Thread {
public:
    virtual -Thread() {}
    // 모든 부모클래스는 가상 소멸자를 제공해야 합니다.

    void run() {
        pthread_t thread;
        pthread_create(&thread, nullptr, &threadLoop, nullptr);
    }
    // 일반함수 포인터에 멤버 함수 포인터는 담을 수 없지만,
    // 정적 멤버 함수 포인터는 담을 수 있습니다.

    void join() {
        pthread_join(thread, nullptr);
    }
    static void* _threadLoop(void* arg) {
        Thread* self = static_cast<Thread*> (arg);
        self->threadLoop();
        return 0;
    }
};
// 스레드 클래스를 설계해봅시다.
// Thread 라이브러리를 사용하는 방법.

class MyTheread : public Thread {
public:
    virtual bool threadLoop() override {
        cout << "MyThread threadLoop" <<endl;
        return true;
    }
};

int main() {
    MyThread t;
    t.run();  // 이 순간 스레드가 생성되어서, 가상함수인 threadLoop()를 수행해야 합니다.

    t.join();
}


