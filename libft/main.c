#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void *ft_memchr(const void *s, int c, size_t n);

int	main(int ac, char **av)
{
	int		i;
	size_t	n;
	char	s[] = {0, 1, 2, 3, 4, 5};

	(void)ac;
	i = 2 + 256;
	n = (size_t)atoi(av[1]);
	memchr(s, i, n);
	printf("original : %d\n",*(int *)memchr(s,i,n));
	printf("copy : %d\n", *(int *)ft_memchr(s, i, n));
}
