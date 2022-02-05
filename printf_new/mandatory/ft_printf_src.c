/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_src.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:29:35 by haryu             #+#    #+#             */
/*   Updated: 2022/02/05 23:12:19 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *len)
{
	int	temp;

	temp = 0;
	temp = write(1, &c, 1);
	if (temp == -1)
	{
		(*len) = -1;
		return ;
	}
	(*len) += temp;
	return ;
}

void	ft_putstr(char *s, int *len)
{
	if (!s)
		s = "(null)";
	while (*s)
		ft_putchar(*s++, len);
}

void	ft_put_integer(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar ('-', len);
	}
	if (n > 9)
		ft_put_integer(n / 10, len);
	ft_putchar(n % 10 + '0', len);
	return ;
}

void	ft_put_unsigned(unsigned int n, int *len)
{
	if (n > 9)
		ft_put_unsigned(n / 10, len);
	ft_putchar(n % 10 + '0', len);
	return ;
}
