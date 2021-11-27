/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:11 by haryu             #+#    #+#             */
/*   Updated: 2021/11/27 16:27:56 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ret;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	ret = (char *)malloc((sizeof(char) * (i + 1)));
	if (!ret)
		return (NULL);
	return ((char *)ft_memmove(ret, s1, i + 1));
}
