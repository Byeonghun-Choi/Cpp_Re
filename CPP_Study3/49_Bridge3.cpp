#include <iostream>
using namespace std;

struct MP3 {
    virtual ~MP3() { }

    virtual void Play() = 0;
    virtual void Stop() = 0;

    // 인터페이스에 기본 구현을 제공하는 것으로 많은 문제가 해결됩니다.
    // virtual void PlayOneMinute() = 0'

};

class MP3Bridge
{
    MP3* pImpl; // Pointer to implementation
    // pImpe Idioms
    // 1. 컴파일러 방화벽
    // 2. 컴파일 속도 최적화
    // => Exceptional C++

    // 프록시는 대리자, 브릿지는 
    // 비슷하지만 다름
public:
    MP3Bridge(MP3* p)
        : pImpl(p)
    {
    }

    void Play() { pImpl -> Play(); }
    void Stop() { pImpl -> Stop(); }
};

class Person {
    MP3* mp3;

public:
    Person(MP3* p)
        : mp3(p)
    {
    }

    void PlayMusic()
    {
        mp3->Play();
        mp3->Stop();

        mp3 -> PlayOneMinute();
    }
};


class SmartPhone : public MP3 {
    
public:
    void Play() override
    {
        cout << "SmartPhone Play Music" << endl;
    }
    void Stop() override
    {
        cout << "SmartPhone Stop Music" << endl;
    }
};


int main()
{
    SmartPhone phone;

    MP3Bridge mp3 (&phone);


    Person person(&mp3);

    person.PlayMusic();
}