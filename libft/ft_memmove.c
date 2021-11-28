/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:57:42 by haryu             #+#    #+#             */
/*   Updated: 2021/11/28 23:14:51 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_dst = dst;
	tmp_src = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst <= src)
		while (len-- > 0)
			*tmp_dst++ = *tmp_src++;
	else
		while (len--)
			*(tmp_dst + len) = *(tmp_src + len);
	return (dst);
}
