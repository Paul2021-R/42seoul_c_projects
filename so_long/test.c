#include "./includes/bonus/so_long_bonus.h"
#include <stdio.h>
#include <sys/time.h>

int	main(int argc, char **argv)
{
	time_t			t;
	struct tm		*lt;
	struct timeval	tv;
	struct timeval	tv2;

	t = gettimeofday(&tv, NULL);
	printf("%lu\n", tv.tv_sec);
	while (1)
	{
		t = gettimeofday(&tv2, NULL);
		if (tv2.tv_usec - tv.tv_usec == 50000)
			printf("good its 0.05s!\n");
		if (tv2.tv_sec - tv.tv_sec == 3)
		{
			printf("%lu\n", tv2.tv_sec);
			printf("t : %ld\n", t);
			printf("under check!\n");
			break ;
		}
	}
	return 0; 
}

//   struct timeval {

//         time_t          tv_sec;         /* seconds */

//         suseconds_t     tv_usec;        /* and microseconds */

//   };



// 출처: https://jink1982.tistory.com/109 [돼민이]



