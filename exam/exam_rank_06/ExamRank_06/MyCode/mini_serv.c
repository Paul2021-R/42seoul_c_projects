#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

typedef struct s_client {
  int id;
  char msg[1024];
} t_client;
int fdMax = 0, nextId = 0;
fd_set readFds, writeFds, activeFds;
char buffRead[120000], buffWrite[120000];
t_client clients[1024];
int loopback = 0b01111111000000000000000000000001;
char* fatal = "Fatal error";
char* wrong = "Wrong number of arguments";

int printError(char* msg) {
  if (msg) {
    write(2, msg, strlen(msg));
  } else {
    write(2, fatal, strlen(fatal));
  }
  write(2, "\n", 1);
  exit(1);
}

void sendAll(int not ) {
  for (int i = 0; i < fdMax; i++) {
    if (FD_ISSET(i, &writeFds) && i != not ) {
      send(i, buffWrite, strlen(buffWrite), 0);
    }
  }
}

int main(int ac, char** av) {
  if (ac != 2) printError(wrong);

  int sockFd = socket(2, 1, 6);
  if (sockFd < 0) printError(NULL);

  FD_ZERO(&activeFds);
  memset(&clients, 0, sizeof(clients));
  fdMax = sockFd;
  FD_SET(sockFd, &activeFds);

  struct sockaddr_in serverAddr;
  socklen_t len;
  memset(&serverAddr, 0, sizeof(serverAddr));

  serverAddr.sin_family = 2;
  serverAddr.sin_addr.s_addr = htonl(loopback);
  serverAddr.sin_port = htons(atoi(av[1]));

  if ((bind(sockFd, (const struct sockaddr*)&serverAddr, sizeof(serverAddr))) <
      0)
    printError(NULL);

  if ((listen(sockFd, 100)) < 0) printError(NULL);

  while (1) {
    readFds = writeFds = activeFds;
    if (select(fdMax + 1, &readFds, &writeFds, NULL, NULL) < 0) continue;
    for (int fdIdx = 0; fdIdx <= fdMax; fdIdx++) {
      if (FD_ISSET(fdIdx, &readFds) && fdIdx == sockFd) {
        int connectFd = accept(sockFd, (struct sockaddr*)&serverAddr, &len);
        if (connectFd < 0) continue;
        fdMax = connectFd > fdMax ? connectFd : fdMax;
        FD_SET(connectFd, &activeFds);
        clients[connectFd].id = nextId++;
        sprintf(buffWrite, "server: client %d just arrived\n",
                clients[connectFd].id);
        sendAll(connectFd);
        break;
      } else if (FD_ISSET(fdIdx, &readFds) && fdIdx != sockFd) {
        int res = recv(fdIdx, buffRead, 120000, 0);
        if (res <= 0) {
          sprintf(buffWrite, "server: client %d just left\n",
                  clients[fdIdx].id);
          sendAll(fdIdx);
          FD_CLR(fdIdx, &activeFds);
          close(fdIdx);
          break;
        } else {
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

  // TODO: sockFD 할당하기
  // TODO: 각종 초기화하기
  // TODO: 서버 설정하기
  // TODO: bind, listen
  // TODO: while문 루프 만들기
}