/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:00:36 by haryu             #+#    #+#             */
/*   Updated: 2021/11/30 13:52:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tmp_src;

	i = 0;
	if (!dest && !src)
		return (NULL);
	tmp_src = (char *)src;
	while (i < n)
	{
		*(char *)(dest + i) = *(tmp_src + i);
		i++;
	}
	return (dest);
}
