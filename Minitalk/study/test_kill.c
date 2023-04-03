#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main( int argc, char *argv[])
{
   if ( argc < 2){
      printf( "사용법: ./a.out [프로세스 ID]\n");
   }
   else{
      kill( atoi( argv[1]), SIGKILL);
   }
}