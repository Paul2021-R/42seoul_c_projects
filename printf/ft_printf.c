/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:23:25 by haryu             #+#    #+#             */
/*   Updated: 2022/01/02 19:05:54 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	int	i;
	int	err;
	int	ret;
	va_list ap;
	va_start(ap, str);
	
	i = 0;
	ret = 0;
	while (str[i])
	{
		err = 0;
		if (str[i] == '%')
		{
			i += 1;
			if (str[i] == 'c')
			{
				ft_putchar (va_arg(ap, int));
				err = 1;
			}
			else if (str[i] == 's')
				err = ft_putstr_len (va_arg(ap, char *));
			else if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u')
				err = switch_integer(va_arg(ap, long long), str[i]);
			else if (str[i] == 'x' | str[i] == 'X')
				err = switch_integer_16(va_arg(ap, long long), str[i]);
			else if (str[i] == 'p')
				err = switch_integer_16(va_arg(ap, unsigned long), str[i]);
			else
			{
				write(1, &str[i], 1);
				err = 1;
			}
			ret += err;
		}
		else
		{
			write(1, &str[i], 1);
			ret += 1;
		}
		if (err == -1)
			return (-1);
		i++;
	}
	va_end(ap);
	return (ret);
}
/*
 * 모든 정수 출력 구분자는 8, 16, 10 을 대응할 수 있어야 한다. 
 * */
