#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int limit;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	limit = ft_strlen(str);
	write(1, str, limit);
	return (limit);
}

#define arr "0123456789abcdef"

int	ft_putnbr(long long n, int base)
{
	int	ret;

	ret = 0;
	if (n < 0 && base == 10)
	{
		ret += write(1, "-", 1);
		n *= -1;
	}
	if (n >= base)
		ret += ft_putnbr(n / base, base);
	ret += write(1, &arr[n % base], 1);
	return (ret);
}

int	ft_printf(const char *str, ... )
{
	int	ret;
	int	i;
	va_list	ap;

	va_start(ap, str);
	i = -1;
	ret = 0;
	while(str[++i])
	{
		if (str[i] != '%')
			ret += write(1, &str[i], 1);
		else 
		{
			i++;
			if (str[i] == 's')
				ret += ft_putstr(va_arg(ap, char *));
			else if (str[i] == 'd')
				ret += ft_putnbr(va_arg(ap, int), 10);
			else if (str[i] == 'x')
				ret += ft_putnbr(va_arg(ap, unsigned int), 16);
		}
	}
	va_end(ap);
	return (ret);
}

#include <stdio.h>
#include <limits.h>

int main(void)
{
	int	ret;
	int	ret2;
	char	*str;

	str = NULL;
	ret = ft_printf("hello world %d %s %x\n", -214748, str, -17);
	ret2 = printf("hello world %d %s %x\n",-2147488, str, -17);
	printf("make : %d origin : %d\n", ret, ret2);
}
