/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:02:46 by haryu             #+#    #+#             */
/*   Updated: 2022/04/14 14:54:16 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	make_len(const char *str, va_list *ap);
static int	switch_str(char *str, va_list *ap);

int	ft_printf(char const *str, ...)
{
	va_list		ap;
	int			ret_len;

	if (!str)
		return (-1);
	va_start(ap, str);
	ret_len = 0;
	ret_len = make_len(str, &ap);
	va_end(ap);
	return (ret_len);
}

static int	make_len(const char *str, va_list *ap)
{
	int		len;
	int		temp;

	len = 0;
	while (*str)
	{
		temp = 0;
		if (*str == '%')
		{
			str++;
			temp = switch_str((char *)str, ap);
			if (temp == -2)
			{
				temp = 0;
				str--;
			}
		}
		else
			temp = write(1, str, 1);
		if (temp == -1)
			return (-1);
		len += temp;
		str++;
	}
	return (len);
}

static int	switch_str(char *str, va_list *ap)
{
	int	ret;

	ret = 0;
	if (*str == '%')
		ft_putchar('%', &ret);
	else if (*str == 'c')
		ft_putchar(va_arg(*ap, int), &ret);
	else if (*str == 's')
		ft_putstr(va_arg(*ap, char *), &ret);
	else if (*str == 'd' || *str == 'i')
		ft_put_integer(va_arg(*ap, int), &ret);
	else if (*str == 'u')
		ft_put_unsigned(va_arg(*ap, unsigned), &ret);
	else if (*str == 'x' || *str == 'X')
		ft_put_hex(va_arg(*ap, unsigned), &ret, str);
	else if (*str == 'p')
		ft_put_pointer_pre(va_arg(*ap, unsigned long long), &ret, str);
	else
		return (-2);
	if (ret == -1)
		return (-1);
	return (ret);
}
