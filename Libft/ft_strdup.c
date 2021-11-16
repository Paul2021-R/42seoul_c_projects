/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:11 by haryu             #+#    #+#             */
/*   Updated: 2021/11/16 17:43:39 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	ret = (char *)malloc(i - 1);
	if (!ret)
		return (NULL);
	while (j < i)
	{
		*(ret + j) = *(char *)(s1 + j);
		j++;
	}
	return (ret);
}
