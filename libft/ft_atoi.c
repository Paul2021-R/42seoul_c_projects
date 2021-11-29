/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:12:29 by haryu             #+#    #+#             */
/*   Updated: 2021/11/29 17:37:41 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		minus;
	int		ret;
	char	*copy;

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
			if (ret == 214748364 && (*(copy + 1) == 8))
				return (-2147483648);
			copy++;
		}
	}
	return (ret * minus);
}
