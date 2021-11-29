/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:27:08 by haryu             #+#    #+#             */
/*   Updated: 2021/11/29 16:32:15 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_write_str(char *str, char const *src1, char const *src2)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(src1))
	{
		if (!*src1)
			continue ;
		*(str + i) = *(src1 + i);
		i++;
	}
	while (i < ft_strlen(src1) + ft_strlen(src2))
	{
		if (!*src2)
			continue ;
		*(str + i) = *(src2 + (i - ft_strlen(src1)));
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (ret == NULL)
		return (NULL);
	ret = ft_write_str(ret, s1, s2);
	return (ret);
}
