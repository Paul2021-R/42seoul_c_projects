/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 22:51:39 by haryu             #+#    #+#             */
/*   Updated: 2022/01/01 03:56:54 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int	switch_integer(long nbr, char specifier)
{
	char		*ret;
	long int	i_max;
	long int	i_min;

	i_max = INT_MAX;
	i_min = INT_MIN;
	if (specifier == 'd' || specifier == 'i')
	{
		if ((int)nbr > i_max || (int)nbr < i_min)
			return (-1);
		ret = ft_itoa((int)nbr);
	}
	else if (specifier == 'u')
		ret = ft_uitoa((unsigned int)nbr);
	if (!ret)
		return (-1);
	else
	{
		ft_putstr(ret);
		//free (&ret);
	}
	return (ft_strlen(ret));
}
