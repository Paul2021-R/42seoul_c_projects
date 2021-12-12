/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:23:13 by haryu             #+#    #+#             */
/*   Updated: 2021/12/12 19:08:47 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strnjoin(char *s1, char *s2, size_t byte)
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
	if (s1)
		ft_memmove(ret, s1, byte);
	if (byte > len1)
		ft_memmove(ret + len1, s2, (byte - len1));
	return (ret);
}

void	free_all(t_str *head, int type)
{}

static size_t	read_n_find(int fd, char *str)//읽기  + newl 찾기 +
{
	size_t	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == 10)
			return (i);
		i++;
	}

	return (0);
}

t_str	*ft_new_list(t_str *lst, int fd)
{
	t_str	*new;
	new = malloc(sizeof(t_str));
	if (!new)
	{
		free_all(lst, fd);
		return(NULL);
	}
	new->i_fd = fd;
	return (new);
}

char	*get_next_line(int fd)
{
	static t_str	*head;
	t_str		*node;
	char		buff[BUFFER_SIZE + 1];
	int		read_cnt;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!head)
	{
		head = malloc(sizeof(t_str));
		if (!head)
		{
			free(head);
			return (NULL);
		}
	}
	node = find_node (head, node, fd);
	while (1)
	{
		read_cnt = read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = '\0';
		node->backup = ft_strnjoin(node->backup, buff, (int)ft_strlen(node->backup) + BUFFER_SIZE);
		if (read_n_find(fd, node->backup))
			break ;
	}
	ret = ft_strnjoin(node->backup, NULL, read_n_find(fd, node->backup) + 1);
	node->backup = ft_strnjoin(node->backup + read_n_find(fd, node->backup) + 1, NULL, ft_strlen(node->backup + read_n_find(fd, node->backup) + 1));
	return (ret);
}
/*
 * 이중 포인터 선언시 ->next = node 안됨 
 * (*head)->next = node  선언으로 ㅜ수정됨 와이? 
 * head를 역참조해야 안에 *next 라는 애가 있음. head->next 라는 뜻은 (*head).next 라서 **head로 선언시 구조체 속으로 들어가지 못함. 주소 값까지만 찾아들어감. 따라서 node 의 경유 *t_str 이므로 해당 연결이 안됨. 
 *
 * */
