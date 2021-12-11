/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:15:57 by haryu             #+#    #+#             */
/*   Updated: 2021/12/10 15:22:29 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		while (len-- > 0)
			*tmp_dst++ = *tmp_src++;
	else
		while (len--)
			*(tmp_dst + len) = *(tmp_src + len);
	return (dst);
}

void	str_free(char *str)
{
	free(str);
	str = NULL;
}

char	*ft_calloc(size_t size)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc(size + 1);
	if (!ret)
	{
		str_free(ret);
		return (NULL);
	}
	i = 0;
	while (i < size + 1)
	{
		ret[i] = 0;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	find_newl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 10);
			break ;
		i++;
	}
	return (i);
}
