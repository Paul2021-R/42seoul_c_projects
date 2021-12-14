/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:10:18 by haryu             #+#    #+#             */
/*   Updated: 2021/12/14 20:40:09 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static char	*make_ret(char *s)
{
	char	*ret;
	size_t	ret_len;
	size_t	i;

	if (!s[0])
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	ret_len = i + 1;
	if (s[i] == '\n')
		ret_len++;
	ret = (char *)malloc(sizeof(char) * (ret_len));
	if (!ret)
		return (NULL);
	i = 0;
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
	size_t	j;
	size_t	len;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	len = ft_strlen(s + i + 1);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i += 1;
	j = 0;
	while (s[i])
		ret[j++] = s[i++];
	ret[j] = '\0';
	free(s);
	return (ret);
}

static t_str	*find_new(t_str *head, int fd)
{
	t_str	*node;
	t_str	*temp;	

	if (head->next == NULL)
	{
		node = malloc(sizeof(t_str));
		head->next = node;
	}
	else 
	{
		temp = head->next;
		if (temp->i_fd == fd)
	}
}

char	*get_next_line(int fd)
{
	static t_str	*head;
	t_str			*node;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!head)
	{
		head = malloc(sizeof(t_str));
		if (!head)
			return (NULL);
	}
	head = 0;
	node = find_new(head, fd);
	if (!node)
	{
		free(head);
		return (NULL);
	}
	node->backup = read_buff(fd, node->backup);
	if (!node->backup)
		return (NULL);
	ret = make_ret(node->backup);
	node->backup = get_new_backup(node->backup);
	if (!node->backup)
		free_all(&head, &node, fd);
	if ((head->next) == NULL)
		free(head);
	return (ret);
}
