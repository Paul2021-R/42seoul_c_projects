/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu </var/mail/root>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:44:27 by haryu             #+#    #+#             */
/*   Updated: 2021/12/23 23:39:00 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_list(t_list *head, t_list *node, int fd)
{}

static	t_list	list_initialing(t_list *head, t_list *node, int fd, int *erro)
{
	if (!head->next)
	{
		node = (t_list)malloc(sizeof(t_list));
		if (!node)
		{
			*erro = = -1;
			return (NULL);
		}
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
			node = (t_list)malloc(sizeof(t_list));
			if (!node)
			{
				*erro = -1;
				return (NULL);
			}
			node->next = 0;
			node->i_fd = fd;
		}
	}
}

static char	*read_find(t_list *head, t_list *node)
{}

static char	*return_renew(t_list *head, t_list *node)
{}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list		*node;
	int		errno;
	char		*ret;

	if (!head)
	{
		head = (t_list)malloc(sizeof(t_list));
		if (!head)
			return (NULL);
		head->next = 0;
	}
	node = list_initialing(head, node, fd, &errno);
	if (node)
	{
		node->backup = read_find(head, node);
		if (!node->backup)
		{
		}
		ret = return_renew(head, node);
		if (!ret)
		{}
	}
	else
	{
		free_list(head, node, errno);
		ret = NULL
	}
	return (ret);
}

/*
 * fd == -1 
 * */
