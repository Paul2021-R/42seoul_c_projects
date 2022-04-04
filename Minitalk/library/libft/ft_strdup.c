/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:11 by haryu             #+#    #+#             */
/*   Updated: 2021/11/29 13:55:38 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ret;

	i = ft_strlen(s1);
	ret = (char *)malloc((sizeof(char) * (i + 1)));
	if (!ret)
		return (NULL);
	return ((char *)ft_memmove(ret, s1, i + 1));
}
