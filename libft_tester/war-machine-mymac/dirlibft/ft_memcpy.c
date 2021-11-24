/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:00:36 by haryu             #+#    #+#             */
/*   Updated: 2021/11/12 22:56:45 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	size_t	i;
	char	*tmp_src;

	i = 0;
	tmp_src = (char *)src;
	if (!dest)
		return (NULL);
	while (i < n)
	{
		*(char *)(dest + i) = *(tmp_src + i);
		i++;
	}
	return (dest);
}
