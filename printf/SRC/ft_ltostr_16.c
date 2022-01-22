/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltostr_16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 03:03:07 by haryu             #+#    #+#             */
/*   Updated: 2022/01/23 00:28:53 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_numlen(long long n)
{
	long long	ret;

	ret = 0;
	while (n >= 0)
	{
		n /= 10;
		ret++;
		if (n == 0)
			break ;
	}
	return (ret);
}

static char	*ft_putnbr(char *str, long n, int limit)
{
	int	i;

	i = -1;
	if (n == 0)
	{
		str[0] = 48;
		//str[1] = 'x';
		//str[2] = '0';
	}
	while (++i < limit && n > 0)
	{
		str[i] = (n % 16) + 48;
		if (str[i] > 57)
			str[i] += 39;
		n /= 16;
	}
	//str[i++] = 'x';
	//str[i] = '0';
	return (str);
}

char	*ft_ltostr_16(long long n)
{
	char	*ret;
	int		len;

	len = ft_numlen(n);
	ret = (char *)ft_calloc((len + 1), sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret = ft_putnbr(ret, n, len);
	ret = ft_strrev(ret);
	return (ret);
}
