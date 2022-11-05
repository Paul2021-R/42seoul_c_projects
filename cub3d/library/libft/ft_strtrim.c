/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:06:40 by haryu             #+#    #+#             */
/*   Updated: 2022/03/24 17:03:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	slen;

	if (!s1)
		return (NULL);
	while (*s1)
	{
		if (!(ft_strchr(set, *s1)))
			break ;
		s1++;
	}
	if (*s1 == '\0')
	{
		ret = (char *)ft_calloc(1, sizeof(char));
		return (ret);
	}
	slen = ft_strlen(s1);
	while (--slen > 0)
		if (!(ft_strrchr(set, *(s1 + slen))))
			break ;
	ret = (char *)malloc(sizeof(char) * (slen + 2));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, slen + 2);
	return (ret);
}
