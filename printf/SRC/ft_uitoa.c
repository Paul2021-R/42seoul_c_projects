/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 03:03:07 by haryu             #+#    #+#             */
/*   Updated: 2022/01/20 14:30:48 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_numlen(unsigned int n)
{
	unsigned int	ret;

	ret = 0;
	while (n > 0)
	{
		n /= 10;
		ret++;
		if (n == 0)
			break ;
	}
	return (ret);
}

static char	*ft_putnbr(char *str, int n, int limit)
{
	int	i;

	i = -1;
	if (n == 0)
		str[0] = 48;
	while (++i < limit && n > 0)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

char	*ft_uitoa(unsigned int n)
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
