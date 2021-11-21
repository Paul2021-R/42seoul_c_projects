/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:18:15 by haryu             #+#    #+#             */
/*   Updated: 2021/11/21 20:47:09 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*ret;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (ret[i])
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	return (ret);
}
