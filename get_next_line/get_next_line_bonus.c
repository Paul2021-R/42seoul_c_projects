/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu </var/mail/root>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:44:27 by haryu             #+#    #+#             */
/*   Updated: 2021/12/27 22:32:32 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*list_initialing(t_list *head, t_list *node, int fd, int *erro)
{
	if (!head->next)
	{
		node = (t_list *)malloc(sizeof(t_list));
		node->i_fd = fd;
		node->next = 0;
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
				free_all_check(&head, &node, fd);
			node->next = 0;
			node->i_fd = fd;
		}
	}
	return (NULL);
}

static char	*read_find(t_list *head, t_list *node, int fd)
{
	char	*buffer;
	int		read_cnt;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_cnt = 1;
	while (read_cnt && !ft_strchr(node->backup, '\n'))
	{
		read_cnt = read(fd, buffer, BUFFER_SIZE);
		if (read_cnt == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_cnt] = '\0';
		node->backup = ft_strjoin(node->backup, buffer);
	}
	free (buffer);
	return (node->backup);
}

static char	*return_renew(t_list *head, t_list *node)
{
	char	*ret;
	int		i;
	int		new_line_len;

	i = 0;
	if (!node->backup[0])
		return (NULL);
	while (node->backup && node->backup[i] != '\n')
		i++;
	new_line_len = i + 1;
	if (node->backup[i] == '\n')
		new_line_len++;
	ret = (char *)malloc(sizeof(char) * (new_line_len));
	if (!ret)
		return (NULL);
	i = 0;
	while (node->backup && node->backup[i] != '\n')
	{
		ret[i] = node->backup[i];
		i++;
	}
	if (node->backup[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

static char	*new_back(t_list *head, t_list *node, int total)
{
	char	*ret;
	int		i;
	int		new_line;

	if (!node->backup)
		return (NULL);
	i = 0;
	while (node->backup && node->backup[i] != '\n')
		i++;
	if (node->backup[i] == '\n')
		i++;
	new_line = i + 1;
	ret = (char *)malloc(sizeof(char *) * (new_line));
	if (!ret)
		return (NULL);
	i = 0;
	while (node->backup && new_line + i <= total)
	{
		ret[i] = node->backup[new_line - 1 + i];
		i++;
	}
	free(node->backup);
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	int				errno;
	int				size;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!head)
	{
		head = (t_list *)malloc(sizeof(t_list));
		if (!head)
			return (NULL);
		head->next = 0;
	}
	node = list_initialing(head, node, fd, &errno);
	node->backup = read_find(head, node, fd);
	ret = return_renew(head, node);
	size = 0;
	while (node->backup[size])
		size++;
	node->backup = new_back(head, node, size);
	if (!node->backup)
		free_all(&head, &node, fd);
	return (ret);
}
