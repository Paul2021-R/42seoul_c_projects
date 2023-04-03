#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler( int signo)
{
   printf( "Ctrl-C 키를 누르셨죠!!\n");
}

int main( void)
{
   printf( "시그널을 받을 때까지 잠수합니다.\n");

   // CTRL-C로 바로 종료되는 것을 막기 위해
   // SIGINT를 사용자 핸들러로 지정했습니다.

   signal( SIGINT, sigint_handler);
   pause();
   printf( "깨어났지만 바로 종료합니다. 안녕~~\n");
}