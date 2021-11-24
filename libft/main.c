#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*res;

	res = ft_itoa(-0);
	printf("0 : %s\n",res);
	free(res);

	res = ft_itoa(9);
	printf("9 : %s\n", res);
	free(res);
	
	res = ft_itoa(-9);
	printf("-9 : %s\n", res);
	free(res);
	
	res = ft_itoa(10);
	printf("10 : %s\n", res);
	free(res);
	
	res = ft_itoa(-10);
	printf("-10 : %s\n", res);
	free(res);
	
	res = ft_itoa(8124);
	printf("8124 : %s\n", res);
	free(res);

	res = ft_itoa(-9874);
	printf("-9874 : %s\n", res);
	free(res);
		
	res = ft_itoa(543000);
	printf("543000 : %s\n", res);
	free(res);

	res = ft_itoa(-2147483648LL);
	printf("-2147483648LL : %s\n",res);
	free(res);
	
	res = ft_itoa(2147483647);
	printf("2147483647 : %s\n", res);
	free(res);
	
	return (0);
}
