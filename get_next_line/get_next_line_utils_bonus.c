/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:19:53 by haryu             #+#    #+#             */
/*   Updated: 2021/12/28 23:51:58 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	if (!s)
		return (NULL);
	ret = (char *)s;
	while (*ret)
	{
		if (*ret == c)
			return (ret);
		ret++;
	}
	return (NULL);
}

static char	*ft_write_str(char *str, char *src1, char *src2)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	while (src1[a])
		a++;
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	len1 = 0;
	while (s1[len1])
		len1++;
	len2 = 0;
	while (s2[len2])
		len2++;
	ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (ret == NULL)
		return (NULL);
	ret = ft_write_str(ret, s1, s2);
	free(s1);
	return (ret);
}

void	free_all(t_list **node, int fd)
{
	t_list	*tmp1;
	t_list	*tmp2;

	(void)fd;
	tmp1 = (*node);
	tmp2 = (*node)->next;
	if ((*node)->i_fd == fd)
	{
		tmp1 = tmp1->next;
		free (*node);
		*node = tmp1;
		return ;
	}
	while (tmp1->next && tmp1->next->i_fd != fd)
		tmp1 = tmp1->next;
	tmp2 = tmp1->next;
	if (tmp2->i_fd == fd)
	{
		tmp1->next = tmp2->next;
		free(tmp2);
		return;
	}
}
