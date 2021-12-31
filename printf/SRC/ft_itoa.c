/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:22:09 by haryu             #+#    #+#             */
/*   Updated: 2022/01/01 03:33:11 by haryu            ###   ########.fr       */
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
		n /= 10;
		ret++;
		if (n == 0)
			break ;
	}
	return (ret + sign);
}

static char	*ft_putnbr(char *str, int n, int limit, int sign)
{
	int	i;
	int	except;

	i = -1;
	except = 0;
	if (n == 0)
		str[0] = 48;
	else if (n == -2147483648)
	{
		n += 1;
		except = 1;
	}
	if (sign == 1)
		n *= -1;
	while (++i < limit && n > 0)
	{
		str[i] = (n % 10) + 48;
		if (except == 1 && i == 0)
			str[i] += 1;
		n /= 10;
	}
	if (sign == 1)
		str[i] = '-';
	return (str);
}

char	*ft_itoa(int n)
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
