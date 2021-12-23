#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	char	*src;
	int		size;

	src = av[1];
	size = atoi(av[2]);
	printf("origin  = [%s]\n", strndup(src, size));
	printf("re-code = [%s]\n", ft_strndup(src, size));
}
