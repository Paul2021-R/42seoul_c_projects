/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu </var/mail/root>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:44:27 by haryu             #+#    #+#             */
/*   Updated: 2021/12/28 13:23:56 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*list_initialing(t_list *head, t_list *node, int fd)
{
	if (!head->next)
	{
		node = (t_list *)malloc(sizeof(t_list));
		node->i_fd = fd;
		node->next = 0;
		head->next = node;
		return (node);
	}
	node = head->next;
	while (node)
	{
		if (node->i_fd == fd)
			return (node);
		node = node->next;
		if (!node)
		{
			node = (t_list *)malloc(sizeof(t_list));
			if (!node)
				return (NULL);
			node->backup = 0;
			node->next = 0;
			node->i_fd = fd;
		}
	}
	return (NULL);
}

static char	*read_find(char *str, int fd)
{
	char	*buffer;
	int		read_cnt;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_cnt = 1;
	while (read_cnt && !ft_strchr(str, '\n'))
	{
		read_cnt = read(fd, buffer, BUFFER_SIZE);
		if (read_cnt == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_cnt] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	return (str);
}

static char	*return_renew(char *str)
{
	char	*ret;
	int		i;
	int		new_line_len;

	if (!str)
		return (NULL);
	i = 0;
	while (str && str[i] != '\n')
		i++;
	new_line_len = i + 1;
	if (str[i] == '\n')
		new_line_len++;
	ret = (char *)malloc(sizeof(char) * (new_line_len));
	if (!ret)
		return (NULL);
	i = 0;
	while (str && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

static char	*new_back(char *str, int total)
{
	char	*ret;
	int		i;
	int		new_line;

	if (!str)
		return (NULL);
	i = 0;
	while (str && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	new_line = i + 1;
	ret = (char *)malloc(sizeof(char *) * (new_line));
	if (!ret)
		return (NULL);
	i = 0;
	while (str && new_line + i < total)
	{
		ret[i] = str[new_line - 1 + i];
		i++;
	}
	free(str);
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	int				size;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!head)
	{
		head = (t_list *)malloc(sizeof(t_list));
		if (!head)
			return (NULL);
		head->i_fd = 0;
		head->next = 0;
	}
	node = 0;
	node = list_initialing(head, node, fd);
	node->backup = read_find(node->backup, fd);
	ret = return_renew(node->backup);
	size = 0;
	while (node->backup[size])
		size++;
	node->backup = new_back(node->backup, size);
	if (!node->backup)
		free_all(&head, &node, fd);
	return (ret);
}
