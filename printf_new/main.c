#include "./mandatory/ft_printf.h"
#include <stdio.h>

int main(void)
{
	int len1 = ft_printf("%m", "");
	ft_printf("%d\n", len1);
	return (0);
}
