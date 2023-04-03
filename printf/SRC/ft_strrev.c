/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 03:16:49 by haryu             #+#    #+#             */
/*   Updated: 2022/01/01 03:33:59 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strrev(char *src)
{
	char	*ret;
	char	temp;
	int		limit;
	int		i;

	ret = src;
	limit = ft_strlen(src);
	i = 0;
	while (i < (int)ft_strlen(src) / 2)
	{
		temp = ret[i];
		ret[i] = ret[limit - 1];
		ret[limit - 1] = temp;
		i++;
		limit--;
	}
	return (ret);
}
