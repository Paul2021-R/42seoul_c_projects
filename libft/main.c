#include "libft.h"
#include <time.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	clock_t	start;
	clock_t	end;
	int	result;

	start = clock();
	result = ft_isdigit((int)av[1][0]);
	printf("ft_isalnum : %d\n", result);
	printf("ft_isalpha : %d\n", ft_isalpha((int)av[1][0]));
	printf("ft_isdigit : %d\n", ft_isdigit((int)av[1][0]));
	printf("ft_return : %d\n", (ft_isalpha((int)av[1][0])) || (ft_isdigit((int)av[1][0])));
	end = clock();
	printf("[time : %f]\n", (float)(end - start)/CLOCKS_PER_SEC);
}
