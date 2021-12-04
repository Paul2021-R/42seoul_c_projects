/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:15:57 by haryu             #+#    #+#             */
/*   Updated: 2021/12/04 22:18:35 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	ret = (char *)s;
	while (1)
	{
		if (*ret == c)
			return (ret);
		if (*ret == '\0')
			return (NULL);
		ret++;
	}
	return (NULL);
}

char	*ft_strndup(char const *s, size_t n)
{
	size_t	i;
	size_t	limit;
	char	*ret;

	i = 0;
	limit = n;
	ret = (char *)malloc((n + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < limit)
	{
		*(ret + i) = *(s + i);
		i++;
	}
	*(ret + i) = '\0';
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
