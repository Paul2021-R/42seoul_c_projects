#include "./mandatory/ft_printf.h"

int main(void)
{
	int ret = ft_printf("hello world%d%k\n",5);
	ft_printf("%d", ret);
}
