#include <netinet/in.h>  // IPPROTO_TCP, INADDR_LOOPBACK
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

// 클라이언트 구조체
typedef struct client {
  int id;
  char msg[1024];
} t_client;
// 구조체 리스트
t_client clients[1024];
// fd_set 타입 변수 3개(read, write, active)
fd_set readFds, writeFds, activeFds;
// fd 최대 값, 다음 id 값
int fdMax = 0;
int idNext = 0;
// 버퍼 리드, 버퍼 라이트용 리스트
char buffRead[120000];
char buffWrite[120000];
int loopback = 0b01111111000000000000000000000001;
#define FATAL "Fatal error";
#define WRONG "Wrong number of arguments";

// 에러 출력 타입
int printError(char* str) {
  char* fatalError = FATAL;
  if (str)
    write(2, str, strlen(str));
  else
    write(2, fatalError, strlen(fatalError));
  write(2, "\n", 1);
  exit(1);
}

void sendAll(int notSendFd) {
  for (int i = 0; i <= fdMax; i++) {
    if (FD_ISSET(i, &writeFds) && (i != notSendFd)) {
      send(i, buffWrite, strlen(buffWrite), 0);
    }
  }
}

int main(int ac, char** av) {
  char* wrong = WRONG;
  if (ac != 2) printError(wrong);

  int sockFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sockFd < 0) printError(NULL);

  FD_ZERO(&activeFds);
  memset(&clients, 0, sizeof(clients));
  fdMax = sockFd;
  FD_SET(sockFd, &activeFds);

  struct sockaddr_in serveraddr;
  socklen_t len;
  memset(&serveraddr, 0, sizeof(serveraddr));

  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(loopback);
  serveraddr.sin_port = htons(atoi(av[1]));

  if ((bind(sockFd, (const struct sockaddr*)&serveraddr, sizeof(serveraddr))) <
      0)
    printError(NULL);

  if (listen(sockFd, 100) < 0) printError(NULL);
  while (1) {
    readFds = writeFds = activeFds;
    if (select(fdMax + 1, &readFds, &writeFds, NULL, NULL) < 0) continue;
    for (int fdIdx = 0; fdIdx <= fdMax; fdIdx++) {
      if (FD_ISSET(fdIdx, &readFds) && fdIdx == sockFd) {
        // TODO: server accept logic
        int confd = accept(sockFd, (struct sockaddr*)&serveraddr, &len);
        if (confd < 0) continue;
        fdMax = confd > fdMax ? confd : fdMax;
        clients[confd].id = idNext++;
        FD_SET(confd, &activeFds);
        sprintf(buffWrite, "server: client %d just arrived\n",
                clients[confd].id);
        sendAll(confd);
        break;
      } else if (FD_ISSET(fdIdx, &readFds) && fdIdx != sockFd) {
        // TODO: client write logic
        int res = recv(fdIdx, buffRead, 120000, 0);
        if (res <= 0) {
          sprintf(buffWrite, "server: client %d just left\n",
                  clients[fdIdx].id);
          sendAll(fdIdx);
          FD_CLR(fdIdx, &activeFds);
          close(fdIdx);
          break;
        } else {
          // TODO: client disconnect logic
          for (int i = 0, j = strlen(clients[fdIdx].msg); i < res; i++, j++) {
            clients[fdIdx].msg[j] = buffRead[i];
            if (clients[fdIdx].msg[j] == '\n') {
              clients[fdIdx].msg[j] = '\0';
              sprintf(buffWrite, "client %d: %s\n", clients[fdIdx].id,
                      clients[fdIdx].msg);
              sendAll(fdIdx);
              memset(&clients[fdIdx].msg, 0, strlen(clients[fdIdx].msg));
              j = -1;
            }
          }
          break;
        }
      }
    }
  }
  return 0;
}
// 전체에게 보내는 대응 함수
// 메인 처리 문
// 서버 초반 설정
// 인자 들어온 것 확인
// 소켓 생성
// 각종 변수 초기화
// sockaddr_in serveraddr로 서버 설정하기
// bind
// listen
// 연결 된 이후 처리 절차(while)
// 1. 서버 연결
// 2. 클라이언트 메시지
// 3. 클라이언트 연결 종료