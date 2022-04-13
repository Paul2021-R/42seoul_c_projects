/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:12:29 by haryu             #+#    #+#             */
/*   Updated: 2022/04/13 23:20:05 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

unsigned long	long_check(unsigned long nbr, int minus)
{
	if (nbr > LONG_MAX && minus == 1)
		return (-1);
	else if (nbr > LONG_MAX && minus == -1)
		return (0);
	return (nbr);
}

static int	str_size_check(char *str, int *minus)
{
	int	ret;
	int	lensize;

	ret = 1;
	if (*str == '-')
		*minus = -1;
	lensize = ft_strlen(str);
	if ((lensize == 10 && *minus == 1) || (lensize == 11 && *minus == -1))
		ret = 0;
	if (lensize < 10)
		ret = 0;
	return (ret);
}

int	ft_atoi(const char *str)
{
	int				minus;
	unsigned long	ret;
	char			*copy;

	minus = 1;
	ret = 0;
	copy = (char *)str;
	while ((9 <= *copy && *copy <= 13) || *copy == 32)
		copy++;
	if (str_size_check(copy, &minus))
		return (0);
	if (*copy == '-' || *copy == '+')
		copy++;
	while (*copy && ft_isdigit(*copy))
	{
		ret = (ret * 10) + (*copy - '0');
		if (ret == 2147483648 && minus != 1)
			return (-2147483648);
		else if (ret == 2147483648 && minus == 1)
			return (0);
		copy++;
	}
	ret = long_check(ret, minus);
	return ((int)ret * minus);
}
