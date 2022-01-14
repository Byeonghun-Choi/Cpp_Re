#include <iostream>
using namespace std;

// 1. google.com
//  => IP 주소로 변환합니다.
//  => 142.250.207.46
//
// 2. IP 주소를 통해, 컴퓨터를 찾고, 그 안에 약속된 프로세스를 찾습니다.
//     컴퓨터의 주소: IP
//    프로세스의 주소: PORT(80)
//     142.250.207.46:80
//
// 3. HTTP(Hyper Text Transfer Protocol)
//   - GET 명령을 날리면, HTML / Javascript / CSS를 전송해줍니다.

// 4. 리눅스에서 네트워크를 통해 데이터를 전송받기 위해서는
//    "소켓 프로그래밍"을 이용합니다.
#include <arpa/inet.h>
#include <netinet/in.h> // sockaddr_in
#include <sys/socket.h>
#include <sys/types.h>

#include <unistd.h>

int main()
{
    // 1. Socket
    int csock = socket(PF_INET, SOCK_STREAM, 0);

    // 2. 주소 지정
    //  => IP / PORT
    struct sockaddr_in addr = {
        0,
    };
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80); // 빅엔디안으로 지정해야 합니다.
    addr.sin_addr.s_addr = inet_addr("142.250.207.46");

    // 3. connect
    int ret = connect(csock, (struct sockaddr*)&addr, sizeof addr);
    if (ret == -1) {
        perror("connect()");
        return -1;
    }

    char str[] = "GET\n";
    // 4. GET 명령을 서버에 전송합니다.
    write(csock, str, strlen(str));

    // 5. read를 통해서 서버로부터 전송된 데이터를 화면에 출력합니다.
    char buf[128];
    int len;
    while ((len = read(csock, buf, sizeof buf)) > 0) {
        printf("%s", buf);
    }

    // 6. 연결을 종료합니다.
    close(csock);
}