/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:31:05 by haryu             #+#    #+#             */
/*   Updated: 2021/11/27 14:58:08 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s;

	tmp_s = (unsigned char *)s;
	if (!*tmp_s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (*(tmp_s + i) == (unsigned char)c)
			return (tmp_s + i);
		i++;
	}
	return (NULL);
}
