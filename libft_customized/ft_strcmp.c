/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 00:20:04 by haryu             #+#    #+#             */
/*   Updated: 2021/12/19 01:37:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char const *s1, char const *s2)
{
	int	i;

	if (!s1 && !s2)
		return (0);
	else if (!s1 && s2)
		return (0 - s2[0]);
	else if (s1 && !s2)
		return (s1[0] - 0);
	i = 0;
	while (s1 && s2)
	{
		if (s1[i] != s2[i])
			break ;
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}
