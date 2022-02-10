#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		printf("인자 입력을 하지 않으셨습니다. 종료합니다.\n%s\a\n", strerror(errno));
		exit(1);
	}
	else 
		printf("인자를 정상 입력하셨습니다.\a\n");
	exit(0);
}
