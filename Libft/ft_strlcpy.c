/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:35:19 by haryu             #+#    #+#             */
/*   Updated: 2021/11/16 19:08:17 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	ret;
	int		i;

	ret = ft_strlen((const char *)src);
	i = 0;
	while (i < (int)(dstsize - 1))
	{
		*(dst + i) = *(src + i);
		if (! *(dst + i) || ! *(src + i))
			break ;
		i++;
	}
	*(dst + i) = '\0';
	return (ret);
}
