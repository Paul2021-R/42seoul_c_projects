#include "libft.h"
#include <stdio.h>
#include <string.h>

int main() {
	int i = 0;
	int A[30] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	int B[30] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

	ft_memmove(A+1, A, sizeof(int)*7);
	ft_memcpy(B+1, B, sizeof(int)*7);

	while(i < 9)
	{
		printf("A[%d]%d\n",i,A[i]);
		i++;
	}
	printf("-----------------------------------------\n");
	i = 0;
	while(i < 9)
	{
		printf("B[%d]%d\n",i,B[i]);
		i++;
	}
}
