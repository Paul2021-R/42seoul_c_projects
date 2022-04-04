/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:35:27 by wildwiser-r       #+#    #+#             */
/*   Updated: 2021/11/29 16:06:19 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)s;
	i = ft_strlen(tmp);
	while (i > 0)
	{
		if (*(tmp + i) == c)
			return (tmp + i);
		i--;
	}
	if (*(tmp + i) == c)
		return (tmp);
	return (NULL);
}
