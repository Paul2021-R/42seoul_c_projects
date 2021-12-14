/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:10:18 by haryu             #+#    #+#             */
/*   Updated: 2021/12/14 12:22:47 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buff(int fd, char *s)
{
	char	*buff;
	int		read_cnt;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_cnt = 1;
	while (!ft_strchr(s, '\n') && read_cnt)
	{
		read_cnt = read(fd, buff, BUFFER_SIZE);
		if (read_cnt == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_cnt] = '\0';
		s = ft_strjoin(s, buff);
	}
	free(buff);
	return (s);
}

static char *make_ret(char *s)
{
	char	*ret;
	size_t	len;
	size_t	ret_len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(ft_strchr(s, '\n')) + 1;
	ret_len = ft_strlen(s) - len;
	ret = (char *)malloc(sizeof(char) * (ret_len + 1));
	if (!ret)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		ret[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

static char	*get_new_backup(char *s)
{
	char	*ret;
	size_t	i;

	i = 0;
	while (s[i] && s[i] !='\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	ret = ft_strjoin(s + i + 1, NULL);
	if (!ret)
		return (NULL);
	free(s);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*ret;
	
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	backup[fd] = read_buff(fd, backup[fd]);
	if (!backup[fd])
		return (NULL);
	ret = make_ret(backup[fd]);
	backup[fd] = get_new_backup(backup[fd]);
	return (ret);
}
