/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:40:20 by haryu             #+#    #+#             */
/*   Updated: 2021/12/14 21:49:46 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ret;
	int		i;

	if (!s)
		return (NULL);
	ret = (char *)s;
	i = 0;
	while (ret[i])
	{
		if (ret[i] == c)
			return (ret + i);
		i++;
	}
	return (NULL);
}

static char	*ft_write_str(char *str, char *src1, char *src2)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = ft_strlen(src1);
	if (src1)
	{
		while (src1[i])
		{
			str[i] = src1[i];
			i++;
		}
	}
	i = 0;
	if (src2)
	{
		while (src2[i])
			str[a++] = src2[i++];
	}
	str[a] = '\0';
	return (str);
}

char	*ft_strjoin(char **s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ret;
	char	*temp;

	if (!s2)
		return (NULL);
	temp = *s1;
	len1 = ft_strlen(temp);
	len2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (ret == NULL)
		return (NULL);
	ret = ft_write_str(ret, temp, s2);
	free(*s1);
	return (ret);
}

void	free_all(t_str **head, t_str **node, int fd)
{
	t_str	*temp;
	t_str	*connect;

	temp = 0;
	(void)fd;
	if ((*node)->next != NULL)
		temp = (*node)->next;
	else if ((*node)->next == NULL)
	{
		connect = (*head)->next;
		while (connect->next)
			connect = connect->next;
		if (connect->next != temp)
			connect->next = temp;
	}
	free(*node);
	node = NULL;
	if ((*head)->next == NULL)
		free(*head);
	return ;
}
