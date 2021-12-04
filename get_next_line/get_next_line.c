/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:45:55 by haryu             #+#    #+#             */
/*   Updated: 2021/12/04 23:01:12 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*ret;
	int		r;
	int		i;

	ret = (char *)malloc(sizeof(char) * 5000);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (1)
	{
		r = read(fd, ret + i, BUFFER_SIZE);
		if (ft_strchr(ret, 10))
			break ;
		i += BUFFER_SIZE;
	}
	return (ret);
}
