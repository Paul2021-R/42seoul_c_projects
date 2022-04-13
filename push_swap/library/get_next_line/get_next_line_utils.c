/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:40:20 by haryu             #+#    #+#             */
/*   Updated: 2022/04/13 21:46:07 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	if (!s)
		return (NULL);
	ret = (char *)s;
	while (*ret)
	{
		if (*ret == c)
			return (ret);
		ret++;
	}
	return (NULL);
}

static char	*ft_write_str(char *str, char *src1, char *src2)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = ft_strlen(src1);
	if (src1)
	{
		while (src1[i])
		{
			str[i] = src1[i];
			i++;
		}
	}
	i = 0;
	if (src2)
	{
		while (src2[i])
			str[a++] = src2[i++];
	}
	str[a] = '\0';
	return (str);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (ret == NULL)
		return (NULL);
	ret = ft_write_str(ret, s1, s2);
	free(s1);
	return (ret);
}
