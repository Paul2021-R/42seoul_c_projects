#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int ac, char **av)
{
	const char		*s1;
	const char		*s2;

	(void)ac;
	s1 = av[1];
	s2 = av[2];
	printf("re-code : ");
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}
