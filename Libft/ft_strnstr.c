/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:20:57 by haryu             #+#    #+#             */
/*   Updated: 2021/11/15 08:36:49 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcheck(const char *big, const char *little, size_t loc)
{
	size_t	ret;
	int		i;

	i = 0;
	ret = loc;
	while (little[i])
	{
		if (big[loc] == little[i])
		{
			i++;
			loc++;
		}
		else if (big[loc] != little[i])
			return (-1);
	}
	return (ret);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		loc;

	i = 0;
	loc = -1;
	while (i < len && haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
			loc = ft_strcheck(haystack, needle, i);
		i++;
	}
	if (loc == -1)
		return (NULL);
	else
		return ((char *)haystack + loc);
}
