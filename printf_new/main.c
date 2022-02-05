
#include "./mandatory/ft_printf.h"
#include <stdio.h>

int main(void)
{
	int len1 = ft_printf("%s\n", "");
	ft_printf("%d\n", len1);
	return (0);
}
