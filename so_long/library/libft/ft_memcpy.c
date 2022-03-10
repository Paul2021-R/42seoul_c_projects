/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:00:36 by haryu             #+#    #+#             */
/*   Updated: 2021/12/02 13:06:34 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_src;

	i = 0;
	if (!dest && !src)
		return (NULL);
	tmp_src = (unsigned char *)src;
	while (i < n)
	{
		*(unsigned char *)(dest + i) = *(tmp_src + i);
		if (i + 1 < n)
			*(unsigned char *)(dest + i + 1) = *(tmp_src + i + 1);
		i += 2;
	}
	return (dest);
}
