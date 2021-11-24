/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:20:57 by haryu             #+#    #+#             */
/*   Updated: 2021/11/22 16:28:48 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcheck(const char *big, const char *little, \
		size_t loc, size_t max_len)
{
	size_t	ret;
	int		i;

	i = 0;
	ret = loc;
	while (loc < max_len)
	{
		if (big[loc] == little[i])
		{
			i++;
			loc++;
			if (little[i] == '\0')
				break ;
			if (loc == max_len && little[i] != '\0')
				ret = -1;
		}
		else if (big[loc] != little[i])
			return (-1);
	}
	return (ret);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		loc;

	i = 0;
	loc = -1;
	if (!*needle)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			loc = ft_strcheck(haystack, needle, i, len);
			if (loc != -1)
				break ;
		}
		i++;
	}
	if (loc == -1)
		return (NULL);
	else
		return ((char *)haystack + loc);
}
