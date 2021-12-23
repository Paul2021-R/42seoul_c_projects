/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:49:14 by haryu             #+#    #+#             */
/*   Updated: 2021/12/19 00:37:40 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < (unsigned int)start)
		sub = ft_strndup((char *)(s), 0);
	else
		sub = ft_strndup((char *)(s + start), len);
	if (!sub)
		return (NULL);
	return (sub);
}
