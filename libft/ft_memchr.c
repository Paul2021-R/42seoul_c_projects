/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:31:05 by haryu             #+#    #+#             */
/*   Updated: 2021/11/29 00:01:28 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;

	tmp_s = (unsigned char *)s;
	if (!*tmp_s)
		return (NULL);
	while (n--)
	{
		if (*(tmp_s) == (unsigned char)c)
			return ((void *)tmp_s);
		tmp_s++;
	}
	return (NULL);
}
