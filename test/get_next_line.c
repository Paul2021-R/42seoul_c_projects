/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:40:23 by atakeddi          #+#    #+#             */
/*   Updated: 2021/12/14 12:28:20 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer(int fd, char *str)
{
	char	*buff;
	int		c;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	c = 1;
	while (!ft_strchr(str, '\n') && c)
	{
		c = read(fd, buff, BUFFER_SIZE);
		if (c == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[c] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*get_line(char *c)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	if (!c[0])
		return (NULL);
	while (c[i] && c[i] != '\n')
		i++;
	len = i + 1;
	if (c[i] == '\n')
		len++;
	line = (char *)malloc(len);
	if (!line)
		return (NULL);
	i = 0;
	while (c[i] && c[i] != '\n')
	{
		line[i] = c[i];
		i++;
	}
	if (c[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_new_rest(char *rest)
{
	char	*new_rest;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	len = ft_strlen(&rest[i + 1]);
	new_rest = (char *)malloc(sizeof(char) * len + 1);
	if (!new_rest)
		return (NULL);
	i++;
	while (rest[i])
		new_rest[j++] = rest[i++];
	new_rest[j] = '\0';
	free (rest);
	return (new_rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = read_buffer(fd, rest);
	if (!rest)
		return (NULL);
	line = get_line(rest);
	rest = get_new_rest(rest);
	return (line);
}
