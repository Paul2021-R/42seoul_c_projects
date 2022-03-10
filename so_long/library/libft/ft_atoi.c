/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:12:29 by haryu             #+#    #+#             */
/*   Updated: 2021/12/01 01:19:01 by haryu            ###   ########.fr       */
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
	if (*copy == '-')
		minus = -1;
	if (*copy == '-' || *copy == '+')
		copy++;
	if (ft_isdigit(*copy))
	{
		while (*copy && ft_isdigit(*copy))
		{
			ret = (ret * 10) + (*copy - '0');
			if (ret == 214748364 && (*(copy + 1) == '8'))
				return (-2147483648);
			copy++;
		}
		ret = long_check(ret, minus);
	}
	return ((int)ret * minus);
}
