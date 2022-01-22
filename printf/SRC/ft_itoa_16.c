/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:22:09 by haryu             #+#    #+#             */
/*   Updated: 2022/01/23 00:23:37 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_numlen(int n, int sign)
{
	int	ret;

	if (n == -2147483648)
		return (11);
	if (sign == 1)
		n *= -1;
	ret = 0;
	while (n >= 0)
	{
		n /= 16;
		ret++;
		if (n == 0)
			break ;
	}
	return (ret + sign);
}

static char	*ft_putnbr(char *str, int n, int limit, int sign)
{
	int			i;
	long long	tmp;

	i = -1;
	tmp = (long long)n;
	if (tmp == 0)
	{
		str[0] = 48;
		//str[1] = 'x';
		//str[2] = '0';
	}
	if (sign == 1)
		tmp *= -1;
	while (++i < limit - 2 && tmp > 0)
	{
		str[i] = (n % 16) + 48;
		if (str[i] > 57)
			str[i] += 39;
		n /= 16;
	}
	//str[i++] = 'x';
	//str[i] = '0';
	if (sign == 1)
		str[++i] = '-';
	return (str);
}

char	*ft_itoa_16(int n)
{
	char	*ret;
	int		sign;
	int		len;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = ft_numlen(n, sign);
	ret = (char *)ft_calloc((len + 1), sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret = ft_putnbr(ret, n, len, sign);
	ret = ft_strrev(ret);
	return (ret);
}
