/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:35:27 by wildwiser-r       #+#    #+#             */
/*   Updated: 2021/11/28 23:22:14 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	size_t	i;

	ret = NULL;
	i = 0;
	while (1)
	{
		if (*(s + i) == (char)c)
			ret = (char *)(s + i);
		if (*(s + i) == '\0')
			break ;
		i++;
	}
	return (ret);
}
