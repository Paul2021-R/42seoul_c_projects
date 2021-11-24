/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:31:01 by haryu             #+#    #+#             */
/*   Updated: 2021/11/22 17:00:16 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	ret;

	i = -1;
	if (n > 0)
		n = (int)(n - 1);
	else
		return (0);
	while ((++i) <= (int)n)
	{
		if (s1[i] != s2[i])
			break ;
		if (!s1[i] || !s2[i])
			break ;
		if (i == (int)n)
			break ;
	}
	ret = (unsigned char)s1[i] - (unsigned char)s2[i];
	return ((unsigned int)ret);
}