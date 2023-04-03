#include <unistd.h>
#include <stdarg.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	ret;

	ret = 0;
	ret = ft_strlen(str);
	return (write(1, str, ret));
}

#define number "0123456789abcdef"

int	ft_putnbr(long long nbr, int base)
{
	int	ret;

	ret = 0;
	if (nbr < 0 && base == 10)
	{
		ret +=	write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= base)
		ret += ft_putnbr(nbr / base, base);
	ret += write(1, &number[nbr % base], 1);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	int		i;
	int		ret;

	va_start(ap, str);
	i = 0;
	ret = 0;
	while(str[i])
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
		i++;
	}
	va_end(ap);
	return (ret);
}

#include <stdio.h>
#include <limits.h>

int main(void)
{
	int ret;
	int ret2;

	ret = ft_printf("hello world %x %s %d\n", 214, "toto", -42);
	ret2 = printf("hello world %x %s %d\n", 214, "toto", -42);
	printf("make : %d origin : %d\n", ret, ret2);
	return (0);
}
