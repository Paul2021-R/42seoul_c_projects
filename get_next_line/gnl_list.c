/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:48:55 by haryu             #+#    #+#             */
/*   Updated: 2021/12/06 00:35:21 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_line	*ft_lstnew(t_line *next, int fd)
{
	t_line	*new;

	new = (t_line *)malloc(sizeof(t_line) * 1);
	if (!new)
		return (NULL);
	new->content = (char *)malloc(sizeof(char) * 1000000);
	if (new->content == NULL)
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

static void	ft_lstadd_back(t_line *all, t_line *new)
{
	if (!all)
		all = new;
	while (all->next)
		all = all->next;
	all->next = new;
}

static int	get_next_newl(int fd, t_line *src)
{
	unsigned int	i;
	unsigned int	get;
	unsigned int	total;

	get = 0;
	total = 0;
	i = 0;
	if (src->end != 0)
		i = src->end;
	while (1)
	{
		get = read(fd, src->content + total + src->end, BUFFER_SIZE);
		if (get == 0)
			total += BUFFER_SIZE;
		else if (get > 0)
			total += get;
		while (src->content[i])
		{
			if (src->content[i] == 10)
				return (i);
			i++;
		}
		if (get == 0)
			break ;
	}
	return ((int)ft_strlen(src->content));
}

char	*get_next_line(int fd)
{
	static t_line	*back;
	unsigned int	i;
	char			*ret;

	if (!back->content)
		ft_lstnew(back->content, fd);
	if (fd != back->fd)
	{
		ft_lstnew(back->next, fd);
		back = back->next;
	}
	i = 0;
	if (back->end != 0)
		i = back->end + 1;
	back->end = get_next_newl(fd, back);
	ret = ft_strndup(back->content + i, back->end - i);
	if (!ret)
		return (NULL);
	return (ret);
}
