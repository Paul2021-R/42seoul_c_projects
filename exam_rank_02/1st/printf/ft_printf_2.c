#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *s)
{
	int ret;

	ret = 0;
	while(s[ret])
		ret++;
	return (ret);
}

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *s)
{
	int ret;
	int	i;

	ret = 0;
	i = 0;
	ret = ft_strlen(s);
	write(1, s, ret);
	return (ret);
}

# define hex "0123456789abcdef"

int ft_putnbr(long long num, int base)
{
	int ret;

	ret = 0;
	if (num < 0)
	{
		ret += ft_putchar('-');
		num *= -1;
	}
	if (num >= base)
		ret += ft_putnbr(num / base, base);	
	ret += ft_putchar(hex[num % base]);
	return (ret);
}

int ft_printf(const char *str, ...)
{
	va_list 	ap;
	char		c;
	char		*s;
	long long	x;
	long long	d;
	int			i;
	int			ret;

	ret = 0;
	i = 0;
	va_start(ap, str);
	while(*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 's')
			{
				s = va_arg(ap, char *);
				ret += ft_putstr(s);
			}
			else if (*str == 'd')
			{
				d = va_arg(ap, int);
				ret += ft_putnbr(d, 10);
			}
			else if (*str == 'x')
			{
				x = va_arg(ap, unsigned int);
				ret += ft_putnbr(x, 16);
			}	
		}
		else
			ret += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (ret);
}

#include <stdio.h>

int	main(void)
{
	int ret;
	int ret2; 

	ret = ft_printf("hello world %d %s %x\n", -42, "hell", -23);
	ret2 = printf("hello world %d %s %x\n", -42, "hell", -23);
	printf("%d %d\n", ret, ret2);
	
}


