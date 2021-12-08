/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:02:45 by haryu             #+#    #+#             */
/*   Updated: 2021/12/08 20:16:44 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_strndup(char *str, size_t n)
{
	size_t	i;
	size_t	limit;
	char	*ret;

	i = 0;
	limit = n;
	ret = (char *)malloc((n + 1) * sizeof(char));
	if (!ret)
	{
		free(ret);
		return (NULL);
	}
	while (i <= limit && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char	*ft_write_str(char *str, char const *src1, char const *src2)
{
	size_t	i;
	size_t	limit;

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

static char	*ft_strjoin(char *s1, char const *s2)
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
	free (s1);
	return (ret);
}

char	*cut_str_newl(char *str)
{
	char	*temp;
	int		size;

	size = (int)ft_strlen(str) - get_next_newl(str);
	temp = (char *)malloc(sizeof(char) * size);
	temp = ft_strndup(str + get_next_newl(str) + 1, size);
	if (!temp)
		return (NULL);
	free(str);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*total;
	char		buff[BUFFER_SIZE + 1];
	int			read_cnt;
	char		*ret;

	if ((fd < 0) || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		read_cnt = read(fd, buff, BUFFER_SIZE);
		if (read_cnt == -1)
			return (NULL);
		buff[BUFFER_SIZE] = '\0';
		total = ft_strjoin(total, buff);
		if (read_cnt < BUFFER_SIZE)
			break ;
		if (get_next_newl(total) != -1)
			break ;
	}
	ret = ft_strndup(total, get_next_newl(total));
	if (!ret || ret[0] == '\0')
		return (NULL);
	total = cut_str_newl(total);
	if (!total)
		return (NULL);
	return (ret);
}
