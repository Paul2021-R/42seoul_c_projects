/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu </var/mail/root>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:44:27 by haryu             #+#    #+#             */
/*   Updated: 2021/12/29 00:07:06 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*list_initialing(t_list *head, t_list *node, int fd)
{
	t_list	*tmp;

	if (!head->next)
	{
		node = (t_list *)malloc(sizeof(t_list));
		node->backup = 0;
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
		tmp = node;
		node = node->next;
		if (node->next == 0)
		{
			node = (t_list *)malloc(sizeof(t_list));
			if (!node)
				return (NULL);
			tmp->next = node;
			node->backup = 0;
			node->next = 0;
			node->i_fd = fd;
			head->next = node;
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

	if (!str[0])
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	new_line_len = i + 1;
	if (str[i] == '\n')
		new_line_len++;
	ret = (char *)malloc(sizeof(char) * (new_line_len));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

static char	*new_back(char *str)
{
	char	*ret;
	int		i;
	int		j;
	int		new_line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_line = 0;
	while ((str + i + 1)[new_line])
		new_line++;
	ret = (char *)malloc(sizeof(char *) * (new_line + 1));
	if (!ret)
		return (NULL);
	i += 1;
	j = 0;
	while (str[i])
		ret[j++] = str[i++];
	ret[j] = '\0';
	free(str);
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
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
	node->backup = new_back(node->backup);
	if (!node->backup)
		free_all(&node, fd);
	return (ret);
}
