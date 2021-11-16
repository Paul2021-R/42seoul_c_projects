/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:01:59 by haryu             #+#    #+#             */
/*   Updated: 2021/11/16 17:12:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*ret;

	ret = (char *)malloc(count * size);
	i = 0;
	while (i < count * size)
	{
		*(ret + i) = 0;
		i++;
	}
	return (ret);
}
