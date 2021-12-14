/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:50:00 by haryu             #+#    #+#             */
/*   Updated: 2021/12/13 20:03:54 by haryu            ###   ########.fr       */
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
	{
		while (len-- > 0 && tmp_dst)
			*tmp_dst++ = *tmp_src++;
		*tmp_dst = '\0';
	}
	else
	{
		*(tmp_dst + len) = '\0';
		while (len-- && tmp_dst)
			*(tmp_dst + len) = *(tmp_src + len);
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static char	*ft_write_str(char *str, char *src1, char const *src2, size_t byte)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(src1) && i < byte)
	{
		if (!*src1)
			break ;
		*(str + i) = *(src1 + i);
		i++;
	}
	while (i < ft_strlen(src1) + ft_strlen(src2) && i < byte)
	{
		if (!*src2)
			break ;
		*(str + i) = *(src2 + (i - ft_strlen(src1)));
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_strnjoin(char *s1, char const *s2, size_t byte)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (ret == NULL)
		return (NULL);
	ret = ft_write_str(ret, s1, s2, byte);
	return (ret);
}
