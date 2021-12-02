#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	long	i; 
	int		j;

	i = atoi(av[1]);
	j = atoi(av[1]);
	printf("long 값[%s] :  %ld\n", av[1], i);
	printf("int 값[%s] : %d\n", av[1], j);
}
