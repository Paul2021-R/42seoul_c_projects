/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:19:21 by haryu             #+#    #+#             */
/*   Updated: 2021/11/19 21:03:50 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*end;
	int		height;
	int		i;

	if (!s)
		return (NULL);
	height = 0;
	while (*s)
	{
		if (*s == c)
		{
			end = ft_strchr(s, c);
			if (end == NULL)
				break ;
			i = 0;
			while (s[i] == *end)
				i++;
			ret[height] = (char *)malloc(sizeof(char) * i);
			if (ret[height] == NULL)
				return (NULL);
			ft_strlcpy(ret[height], s, i - 1);
			s = end + 1;
			height++;
		}
		else
			s++;
	}



	return (ret);
}
/*
 * 포인트 1) 문장이 주어지고, 그 문장이 정상적이지 않으면, 지금까지 전체 진행 사항을 free하고 널값을 출력해야 한다. 
 * 포인트 2) 단순 반복문으로 진행시 필요한 경우의 수가 너무 많고, FREE 기능을 못 씀. 
 * */
