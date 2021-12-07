/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:02:45 by haryu             #+#    #+#             */
/*   Updated: 2021/12/07 22:00:21 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	get_next_newl(char *findstr)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(findstr))
		if (findstr[i] == 10)
			return (i);
	return (0);
}

static char	*ft_strndup(char *str, size_t n)
{
	size_t	i;
	size_t	limit;
	char	*ret;

	i = 0;
	limit = n;
	ret = (char *)malloc((n + 1) * sizeof(char));
	if (!ret)
	{	free(ret);
		return (NULL);
	}
	while (i < limit && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char *free_with_join2(char *back, char *buffer)
{
	char	*temp;
	int		size;

	size = ft_strlen(buffer + get_next_newl(buffer));
	printf("<size>\n[%d]\n", size);
	printf("\n[%s]\n", buffer + get_next_newl(buffer) + 1);
	temp = ft_strndup(buffer + get_next_newl(buffer) + 1, BUFFER_SIZE);
	printf("<back>\n[%s]\n", back);
	printf("<buffer>\n[%s]\n", buffer);
	printf("<temp>\n[%s]\n\n\n", temp);
	free(back);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*back[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int		end_addr;
	char		*ret;

	if ((fd < 0) || BUFFER_SIZE <= 0)
		return (NULL);
	end_addr = 1;
	while (end_addr != 0)
	{
		end_addr = read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = '\0';
		back[fd] = ft_strjoin(back[fd], buff);
		if (end_addr == 0)
			break ;
		if (get_next_newl(back[fd]))
			break ;
	}
	ret = ft_strndup(back[fd], get_next_newl(back[fd]));
	back[fd] = free_with_join2(back[fd], buff);
	return (ret);
}
