/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:15:57 by haryu             #+#    #+#             */
/*   Updated: 2021/12/08 17:21:38 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	get_next_newl(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = (int)ft_strlen(str);
	while (i < size)
	{
		if (str[i] == 10)
			return (i);
		i++;
	}
	return (-1);
}

char	*str_initialize(char *str)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
