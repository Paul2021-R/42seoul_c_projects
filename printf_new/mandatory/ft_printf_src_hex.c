/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_src_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:45:42 by haryu             #+#    #+#             */
/*   Updated: 2022/01/23 23:32:31 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ref_base(char *ref)
{
	if (*ref =='X')
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

void	ft_put_hex(unsigned int n, int *len, char *ref)
{
	char	*refer;

	refer = ref_base(ref);
	if (n > 15)
		ft_put_hex(n / 16, len, ref);
	ft_putchar(refer[n % 16], len);
	return ;
}

void	ft_put_pointer(unsigned long long n, int *len, char *ref)
{
	char	*refer;

	refer = ref_base(ref);
	if (n > 15)
		ft_put_pointer(n / 16, len, ref);
	ft_putchar(refer[n % 16], len);
}

void	ft_put_pointer_pre(unsigned long long n, int *len, char *ref)
{
	if (n == 0)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	ft_putstr("0x", len);
	ft_put_pointer(n, len, ref);
	return ;
}
