/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 22:51:39 by haryu             #+#    #+#             */
/*   Updated: 2022/01/01 11:06:05 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	switch_integer(long long nbr, char specifier)
{
	char		*ret;
	
	if (specifier == 'd' || specifier == 'i')
	{
		if ((long)nbr > INT_MAX || (long)nbr < INT_MIN)
			return (-1);
		ret = ft_itoa((int)nbr);
	}
	else if (specifier == 'u')
	{
		if((long long)nbr > UINT_MAX)
			return (-1);
		ret = ft_uitoa((unsigned int)nbr);
	}
	if (!ret)
		return (-1);
	else
		ft_putstr(ret);
	return (ft_strlen(ret));
}
