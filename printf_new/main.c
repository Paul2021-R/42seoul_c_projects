#include "./mandatory/ft_printf.h"
#include <stdio.h>

int main(void)
{
	int len1 = ft_printf("%d%\n", 123);
	int len2 = printf("%d%\n", 123);
	ft_printf("%d %d\n", len1, len2);
	return (0);
}
