/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:35:38 by haryu             #+#    #+#             */
/*   Updated: 2021/12/13 20:05:21 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_n_find(char *str)
{
	size_t	i;

	i = 0;
	while (&str[i])
	{
		if (str[i] == 10)
			return (i);
		i++;
	}
	return (-1);
}

static void	*return_n_backup(char **str, char **ret)
{
	char	*temp;
	char	*ret_t;
	int		size;

	size = read_n_find(*str);
	ret_t = ft_strnjoin(*str, NULL, size + 1);
	*ret = ret_t;
	temp = ft_strnjoin(*str + size + 1, NULL, ft_strlen(*str + size + 1) + 1);
	free(*str);
	*str = temp;
	return (ret);
}

static char	*ft_free(char **lost)
{
	if (*lost)
		free(*lost);
	*lost = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*total;
	char		buff[BUFFER_SIZE + 1];
	char		*ret;
	int			read_cnt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		read_cnt = read(fd, buff, BUFFER_SIZE);
		if (read_cnt == 0 || read_cnt < 0)
		{
			if (total && total[0] == '\0')
				ret = ft_free(&total);
			return (NULL);
		}
		buff[BUFFER_SIZE] = '\0';
		if (!total)
			total = ft_strnjoin(buff, NULL, read_cnt);
		else
			total = ft_strnjoin(total, buff, ft_strlen(total) + read_cnt);
		if (read_n_find(total) != -1)
			break ;
	}
	return_n_backup(&total, &ret);
	return (ret);
}
