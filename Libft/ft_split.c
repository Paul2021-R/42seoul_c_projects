/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:52:51 by haryu             #+#    #+#             */
/*   Updated: 2021/11/19 18:57:12 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_height_check(char const *s, char c)
{
	int	height;
	int	checker;
	int	i;

	height = 0;
	i = -1;
	while (++i < ft_strlen(s))
	{
		if (s[i] != c)
			checker++;
		if (s[i] == c)
		{
			if (checker != 0)
			{
				height++;
				checker = 0;
			}
			else
				checker = 0;
		}
		if (i == ft_strlen(s) - 1 && s[i] != c)
			height++;
	}
	return (height);
}

int	ft_width_check(char const *s, char c)
{
	int	end;
	int	i;

	i = 0;
	end = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == c)
			break ;
		end++;
		i++;
	}
	return (end);
}

char	**ft_one_line(const char *s)
{
	char	**ret;
	 int	len;

	len = (int)ft_strlen(s);
	ret = (char **)malloc(sizeof(char *) * 1);
	ret[0] = (char *)malloc(sizeof(char) * (len + 1));
	ret[0] = ft_strdup(s);
	return (ret);
}

char	**ft_str_cp(char const *s, char **dst, char c)
{
	int	i;
	int	height;
	int	width;

	i = 0;
	height = ft_height_check(s, c);
	while (i < height)
	{
		if (s[0] != c || *s == c)
		{
			width = ft_width_check(s, c);
			if (width != 0)
			{
				dst[i] = (char *)malloc(sizeof(char) * (width + 1));
				if (dst == NULL)
					return (NULL);
				ft_strlcpy(dst[i], s, (size_t)width + 1);
				i++;
			}
			if (i == height)
				break ;
			s += width;
		}
		s++;
	}
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	 int	height;
	 int	width;

	height = ft_height_check(s, c);
	width = ft_width_check(s, c);
	if (!s)
		return (NULL);
	if (height == 0 && width == (ft_strlen(s) - 1))
		ret = ft_one_line(s);
	ret = (char **)malloc(sizeof(char *) * height);
	if (ret == NULL)
		return (NULL);
	ret = ft_str_cp(s, ret, c);
	return (ret);
}
