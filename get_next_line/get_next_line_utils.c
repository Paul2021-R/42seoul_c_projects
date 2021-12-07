/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:15:57 by haryu             #+#    #+#             */
/*   Updated: 2021/12/07 17:36:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

char	*ft_write_str(char *str, char const *src1, char const *src2)
{
	size_t	i;
	int	limit;
	int	limit2;

	i = 0;
	if (!src1)
		limit = 0;
	else
		limit = ft_strlen(src1);
	while (i < limit)
	{
		*(str + i) = *(src1 + i);
		i++;
	}
	while (i < limit + ft_strlen(src2) + 1)
	{
		str[i] = src2[i - limit];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	if (!s1)
		len1 = 0;
	else
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (ret == NULL)
	{
		free(ret);
		return (NULL);
	}
	ret = ft_write_str(ret, s1, s2);
	return (ret);
}
