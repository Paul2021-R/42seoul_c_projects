#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	max;
	
	max = sysconf(_SC_OPEN_MAX);
	printf("OPEN_MAX : %d\n", max);
	max = sysconf(FOPEN_MAX);
	printf("FOPEN_MAX : %d\n", max);
	return (0);
}
