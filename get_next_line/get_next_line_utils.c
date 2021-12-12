/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:23:40 by haryu             #+#    #+#             */
/*   Updated: 2021/12/12 19:08:11 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		while (len-- > 0 && tmp_dst)
			*tmp_dst++ = *tmp_src++;
		*tmp_dst = '\0';
	}
	else
	{
		*(tmp_dst + len) = '\0';
		while (len-- && tmp_dst)
			*(tmp_dst + len) = *(tmp_src + len);
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

t_str	*find_node(t_str *head, t_str *list, int fd)
{
	if (list->i_fd == 0)
	{
		list = ft_new_list(head, fd);
		if (!list)
		{
			free(list);
			return (NULL);
		}
		head->next = list;
	}
	while (list)
	{
		if (list->i_fd == fd)
			break ;
		else
			list = list->next;
		if (list->next == NULL)
		{
			list->next=ft_new_list(head, fd);
			if(!list->next)
			{
				free_all(head, fd);
				return (NULL);
			}	
		}
	}
	return (list);
}
