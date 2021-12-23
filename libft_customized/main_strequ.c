#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	(void)ac;
	printf("re-code = %d\n", ft_strequ(av[1], av[2]));
	printf("%d\n", ft_strcmp(av[1], av[2]));
	return (0);
}
