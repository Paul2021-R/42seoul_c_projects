/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:02:45 by haryu             #+#    #+#             */
/*   Updated: 2021/12/09 12:33:18 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	str_free(char *str);

static char	*ft_strndup(char *str, size_t n)
{
	char	*ret;

	n = (int)n;
	if (n == -1)
		n = (int)ft_strlen(str);
	ret = (char *)malloc((n + 1) * sizeof(char));
	if (!ret)
	{
		str_free(str);
		return (NULL);
	}
	ft_memmove(ret, str, n + 1);
	return (ret);
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
	if (!s2)
		len2 = 0;
	else
		len2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (ret == NULL)
	{
		free(ret);
		return (NULL);
	}
	ft_memmove(ret, s1, len1);
	str_free(s1);
	ft_memmove(ret + len1, s2, len2);
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
	str_free(str);
	return (temp);
}

static void	str_free(char *str)
{
	free(str);
	str = NULL;
	return ;
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
		if (!total)
		{
			total = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
			if (!total)
				str_free(total);
			ft_memmove(total, buff, BUFFER_SIZE + 1);
		}
		else
			total = ft_strjoin(total, buff);
		if (get_next_newl(total) != -1 || read_cnt < BUFFER_SIZE)
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
