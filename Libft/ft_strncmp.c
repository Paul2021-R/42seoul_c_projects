/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:31:01 by haryu             #+#    #+#             */
/*   Updated: 2021/11/12 17:37:42 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	limit;
	int	ret;

	i = -1;
	if (n > 0)
		n = (int)(n - 1);
	else
		return (0);
	while ((++i) <= n)
	{
		if (s1[i] != s2[i])
			break ;
		if (!s1[i] || !s2[i])
			break ;
	}
	ret = s1[i] - s2[i];
	return (ret);
}
