/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:23:13 by haryu             #+#    #+#             */
/*   Updated: 2021/12/10 17:52:57 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnjoin(char *s1, char *s2, size_t byte)
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
	ft_memmove(ret, s1, byte);
	if (byte > len1)
		ft_memmove(ret + len1, s2, (byte - len1));
	return (ret);
}

void	free_all(t_str *lst, int type)
{}

static t_str	ft_init_node(t_str **lst, int fd, t_str *list)
{
	if (!list)
	{
		list = malloc(sizeof(t_str));
		if (list)
			free(list);
		list->next = NULL;
		list->i_fd  = fd;
	}
	while (list)
	{
		if (list->i_fd == fd)
			break ;
		if (list->next == NULL)
		{
			list= malloc(sizeof(t_str));
			if (!list)
				free(list);
			list = list->next;
		}
	}
	return (list);
}

static char	*read_n_find(int fd, t_str *node)//읽기  + newl 찾기 +
{
	char *ret;
}

char	*get_next_line(int fd)
{
	static t_str	**head;
	t_str		*node;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!head)
	{
		head = malloc(sizeof(t_str*));
		if (!head)
		{
			free(head);
			return (NULL);
		}
	}
	node = ft_init_node (head, fd, node);
	
	return (ret);
}
