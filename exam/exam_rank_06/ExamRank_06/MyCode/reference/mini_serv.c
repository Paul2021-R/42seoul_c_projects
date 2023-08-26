#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

typedef struct s_clients {
  int id;
  char msg[1024];
} t_clients;

t_clients clients[1024];
fd_set readfds, writefds, active;
int fdMax = 0, idNext = 0;
char bufferRead[120000], bufferWrite[120000];

void ftError(char *str) {
  if (str)
    write(2, str, strlen(str));
  else
    write(2, "Fatal error", strlen("Fatal error"));
  write(2, "\n", 1);
  exit(1);
}

void sendAll(int not ) {
  for (int i = 0; i <= fdMax; i++)
    if (FD_ISSET(i, &writefds) && i != not )
      send(i, bufferWrite, strlen(bufferWrite), 0);
}

int main(int ac, char **av) {
  if (ac != 2) ftError("Wrong number of arguments");

  int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  // 도메인, type, 프로토콜
  // 도메인 : AF_INET -> IPv4 주소체계를 의미함.
  // type : 소켓 타입을 지정하는 것
  // SOCK_STREAM : TCP 를 사용하는 스트림 소켓으로 연결지향적인 통신을 지원.
  // 데이터는 연속적인 스트림으로 전송된다. SOCK_DGRAM : UDP를 사용하는
  // 데이터그램 소켓으로 비연결성 통신을 지원한다. 데이터 개별 패킷으로
  // 전송된다.
  // protocol : 기본 0으로 사용하여 시스템이 자동으로 적절하게 프로토콜을 선택
  // 가능. TCP인 경우 'IPPROTO_TCP', UDP 인경우 'IPPROTO_UDP' 를 사용 가능
  if (sockfd < 0) ftError(NULL);

  FD_ZERO(&active);
  // FD 집합 초기화 하는 매크로, fd_set 타입에 대한 초기화용.
  //   bzero(&clients, sizeof(clients));
  // 특정 메모리 영역을 사이즈만큼 초기화하는 역할을 하는 함수.
  memset(&clients, 0, sizeof(clients));
  // 현대적인 C프로그래밍 기준에선 memset 을 사용하는 것이 권장된다.
  fdMax = sockfd;
  // fdMax는 현재 할당된 최대 값이기도하고, 따라서 초기화용으로 사용된다.
  FD_SET(sockfd, &active);
  // 파일 디스크립터 집합에 특정 파일 디스크립터를 추가하는 매크로. fd_set 으로
  // 지정된 값에 추가하는 용도.

  struct sockaddr_in servaddr;
  // 서버 구조체
  socklen_t len;
  // 길이값용

  bzero(&servaddr, sizeof(servaddr));
  // 초기화

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(2130706433);  // 127.0.0.1
  servaddr.sin_port = htons(atoi(av[1]));
  // 서버 구조체 설정, 필수 설정은 AF_INET, s_addr, sin_port 이다.

  if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) < 0)
    ftError(NULL);
  // bind
  // (const struct sockaddr *) 형변환
  if (listen(sockfd, 10) < 0) ftError(NULL);
  // listen 함수

  while (1) {
    readfds = writefds = active;
    // 에러 상황 발생시 무시
    if (select(fdMax + 1, &readfds, &writefds, NULL, NULL) < 0) continue;
    for (int fdI = 0; fdI <= fdMax; fdI++) {
      if (FD_ISSET(fdI, &readfds) && fdI == sockfd) {
        // FD_ISSET
        // fdI == sockfd : 소켓에 이벤트 들어온 경우
        int connfd = accept(sockfd, (struct sockaddr *)&servaddr, &len);
        // 새로운 연결
        if (connfd < 0) continue;
        // 에러 무시
        fdMax = connfd > fdMax ? connfd : fdMax;
        // connfd 가 fdMax 보다 크게 할당 된 경우 fdMax 값을 수정한다(최대치
        // 바꾸기)
        clients[connfd].id = idNext++;
        // id 값을 지정해주고, 다음 idNext 값은 1 증가 시켜둠.
        FD_SET(connfd, &active);
        // 활성화된 fd_set에 지정해줌.
        sprintf(bufferWrite, "server: client %d just arrived\n",
                clients[connfd].id);
        // 보내야할 값을 bufferWrite 변수에 입력함.
        sendAll(connfd);
        // 현재 들어와 있는 모든 유저에게 전달함.
        break;
        // 들어온 작업을 모두 마침(클라이언트 등록)
      }
      if (FD_ISSET(fdI, &readfds) && fdI != sockfd) {
        // 들어온 FdI가 소켓이 아니므로 클라이언트인 경우
        int res = recv(fdI, bufferRead, 120000, 0);
        // sockfd: 데이터를 수신할 소켓의 파일 디스크립터다.
        // buf : 수신한 데이터를 저장할 버퍼의 포인터다.
        // len : 수신할 데이터의 최대 길이를 나타냅니다. buf 버퍼의 크기보다
        // 작거나 같아야합니다. flags : 수신 옵션을 나타내는
        // 플래그입니다.일반적으로 0을 사용합니다.recv 함수는 호출되면,
        // 소켓으로부터 데이터를 읽어서 지정한 버퍼(buf)에 저장합니다.len 바이트
        // 만큼의 데이터를 읽지 않을 수도 있으며, 실제로 읽은 데이터의 길이를
        // 반환합니다. 만약 에러가 발생하거나 연결이 끈어진 경우,
        // recv 함수는 -1을 반환하고 에러의 종류는 errno 변수를 통해 확인할 수
        // 있다.
        if (res <= 0) {
          // 해당 경우는 연결이 끊어진 경우다. 따라서 해당 대상을 위한 구조체를
          // 정리해야한다.
          sprintf(bufferWrite, "server: client %d just left\n",
                  clients[fdI].id);
          sendAll(fdI);
          FD_CLR(fdI, &active);
          // FD_CLR : fd_set 에서 삭제 하는경우
          close(fdI);
          // fd 정리
          break;
        } else {
          for (int i = 0, j = strlen(clients[fdI].msg); i < res; i++, j++) {
            clients[fdI].msg[j] = bufferRead[i];
            if (clients[fdI].msg[j] == '\n') {
              clients[fdI].msg[j] = '\0';
              sprintf(bufferWrite, "client %d: %s\n", clients[fdI].id,
                      clients[fdI].msg);
              sendAll(fdI);
              memset(&clients[fdI].msg, 0, strlen(clients[fdI].msg));
              j = -1;
              // for 문 점화식에서 처음에만 길이가 0으로 초기화 되고, 계속
              // 늘어나는 만큼 j 값을 바꿔주는데 이를 for문 점화식으로 풀어
              // 내려고 하니 개행 다음 값을 넣기 위해 j = 0으로 만들기 위함이다.
            }
          }
          break;
        }
      }
    }
  }
}
