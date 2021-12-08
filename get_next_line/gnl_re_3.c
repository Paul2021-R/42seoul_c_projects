/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:02:45 by haryu             #+#    #+#             */
/*   Updated: 2021/12/08 14:40:47 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	get_next_newl(char *findstr)
{
	int	i;
	int	size;

	i = 0;
	size = (int)ft_strlen(findstr);
	while (i < size)
	{
		if (findstr[i] == 10 || findstr[i] == '\0')
			return (i);
		i++;
	}
	return (size);
}

static char	*free_with_renew(char *back)
{
	char	*temp;
	int		newl_cnt;
	
	newl_cnt = ft_strlen(back);
	temp = ft_strndup(back + get_next_newl(back) + 1\
			, newl_cnt - get_next_newl(back));
	free (back);
	return (temp);
}

static char	*str_initialize(char *str)
{
	int	i;
	
	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*back[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			read_cnt;
	char		*ret;

	if ((fd < 0) || BUFFER_SIZE <= 0)
		return (NULL);
	read_cnt = BUFFER_SIZE;
	while (1)
	{
		read_cnt = read(fd, buff, BUFFER_SIZE);
		if (read_cnt == -1)
			return (NULL);
		if (read_cnt < BUFFER_SIZE)
			break ;
		buff[BUFFER_SIZE] = '\0';
		back[fd] = ft_strjoin(back[fd], buff);
		str_initialize(buff);
		if (get_next_newl(back[fd]) !=\
				(int)ft_strlen(back[fd]))
			break ;
	}
	ret = ft_strndup(back[fd], get_next_newl(back[fd]));
	if (!ret)
		return (NULL);
	back[fd] = free_with_renew(back[fd]);
	if (back[fd][0] == '\0' && ret[0] == '\0')
		return (NULL);
	return (ret);
}
