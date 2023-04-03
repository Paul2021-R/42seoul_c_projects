/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_integer_16.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 11:01:02 by haryu             #+#    #+#             */
/*   Updated: 2022/01/16 15:29:23 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*switch_integer_16(long long nbr, char specifier)
{
	char	*ret;
	int		i;

	if (specifier == 'x')
	{
		if ((long)nbr > INT_MAX || (long)nbr < INT_MIN)
			return (NULL);
		ret = ft_itoa_16((int)nbr);
	}
	else if (specifier == 'X')
	{
		if ((long)nbr > INT_MAX || (long)nbr < INT_MIN)
			return (NULL);
		ret = ft_itoa_16((int)nbr);
		i = -1;
		while (ret[++i])
			ret[i] = ft_toupper(ret[i]);
	}
	else
		ret = ft_ltostr_16(nbr);
	if (!ret)
		return (NULL);
	return (ret);
}
