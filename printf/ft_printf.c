/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:57:11 by haryu             #+#    #+#             */
/*   Updated: 2022/01/23 00:25:46 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	make_len(char *str, va_list ap);
static int	switch_str(char *str, va_list ap);

int ft_printf(const char *str, ...)
{
	int		ret_len;
	va_list	ap;

	if (!str)
		return (0);
	va_start(ap, str);
	ret_len = 0;
	ret_len = make_len((char *)str, ap);
	if (ret_len < 0)
		return (-1);
	va_end(ap);
	return (ret_len);
}

static int	make_len(char *str, va_list ap)
{
	int	i;
	int	ret;
	int	temp;

	i = 0;
	ret = 0;
	temp = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			temp = switch_str(str + i, ap);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			temp = 1;
		}
		if (temp < 0)
			return (-1);
		ret += temp;
		i++;
	}
	return (ret);
}

static int	switch_str(char *str, va_list ap)
{
	int 	ret;
	char	*print;
	char	temp;

	ret = 0;
	if (str[1] == 'c')
	{
		temp = va_arg(ap, int);
		write(1, &temp, 1);
		return (1);
	}
	else if (str[1] == 's')
		print = ft_strdup(va_arg(ap, char *));
	else if (str[1] == 'd' || str[1] == 'i' || str[1] == 'u')
		print = switch_integer(va_arg(ap, int), str[1]);
	else if (str[1] == 'x' || str[1] == 'X' || str[1] == 'p')
	{
		print = switch_integer_16(va_arg(ap, long long), str[1]);
		if (str[1] == 'p')
			ft_putstr("0x");
	}
	else
	{	
		write(1, "%", 1);
		return (1);
	}
	if (print != NULL)
	{
		ft_putstr(print);
		ret = ft_strlen(print);
		if (str[1] == 'p')
			ret += 2;
		free (print);
	}
	else
	{
		ft_putstr("(null)");
		ret = 6;
	}
	return (ret);
}
