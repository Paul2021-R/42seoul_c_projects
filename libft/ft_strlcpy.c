/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:35:19 by haryu             #+#    #+#             */
/*   Updated: 2021/11/30 13:53:23 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;
	size_t	i;

	ret = ft_strlen((const char *)src);
	i = 0;
	while (i + 1 < dstsize)
	{
		*(dst + i) = *(src + i);
		if (! *(dst + i) || ! *(src + i))
			break ;
		i++;
	}
	if (dstsize != 0)
		*(dst + i) = '\0';
	return (ret);
}
