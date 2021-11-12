/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:12:29 by haryu             #+#    #+#             */
/*   Updated: 2021/11/13 00:14:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_minus_ck(char *str)
{
	int	ret;

	ret = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			ret += -1;
		else if (*str == '+')
			ret += 1;
		str++;
	}
	if (ret == -1 || ret == 1)
		return (ret);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	 int	minus;
	 int	ret;
	char	*copy;

	minus = 0;
	ret = 0;
	copy = (char *)str;
	while ((9 <= *copy && *copy <= 13) || *copy == 32)
		copy++;
	minus = ft_minus_ck(copy);
	if (minus == 0)
		return (0);
	copy++;
	if (48 <= *copy && *copy <= 57)
	{
		while (*copy && (48 <= *copy && *copy <= 57))
		{
			ret *= 10;
			ret = ret + (*copy - 48);
			copy++;
		}
	}
	return (ret * minus);
}
