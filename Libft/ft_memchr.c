/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:31:05 by haryu             #+#    #+#             */
/*   Updated: 2021/11/16 16:45:19 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s;

	if (!*(unsigned char *)s)
		return (NULL);
	i = 0;
	tmp_s = (unsigned char *)s;
	while (i < n)
	{
		if (*(tmp_s + i) == (char)c)
			return (tmp_s + i);
		i++;
	}
	return (NULL);
}
