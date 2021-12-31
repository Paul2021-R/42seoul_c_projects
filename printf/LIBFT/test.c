#include "libft.h"
#include <stdio.h>

int main(void)
{
	int a = 100;
	int	b = 012;
	int c = 0x14;

	printf("10진수 :%s\n",ft_itoa(a));
	printf("8진수 :%s\n",ft_itoa(b));
	printf("16진수 :%s\n",ft_itoa(c));
}
