#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

extern int ft_atoi(const char *str);

int	main(int ac, char **av)
{
	(void)ac;
	printf("origin : %d\n", atoi(av[1]));
	printf("re-code : %d\n", ft_atoi(av[1]));
	return (0);
}
