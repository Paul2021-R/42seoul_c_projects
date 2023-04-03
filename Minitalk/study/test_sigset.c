#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main()
{
	sigset_t	set;

	printf("%lu", sizeof(sigset_t));
	sigemptyset(&set);
	while(1)
	{
		sigaddset(&set, SIGUSR1);
		printf("%d\n", set);
		sleep(1);
	}
	return (0);
}