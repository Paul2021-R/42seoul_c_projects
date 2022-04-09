/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:06:40 by haryu             #+#    #+#             */
/*   Updated: 2022/04/04 23:14:41 by haryu            ###   ########.fr       */
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
		ret = (char *)ft_calloc(2, sizeof(char));
		if (!ret)
			return (NULL);
		return (ret);
	}
	slen = ft_strlen(s1);
	while (--slen > 0)
		if (!(ft_strrchr(set, *(s1 + slen))))
			break ;
	ret = (char *)malloc(sizeof(char) * (slen + 2));
	ft_strlcpy(ret, s1, slen + 2);
	return (ret);
}
