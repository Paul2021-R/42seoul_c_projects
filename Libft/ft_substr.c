/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:49:14 by haryu             #+#    #+#             */
/*   Updated: 2021/11/18 12:26:37 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (str_len < len)
		len = str_len;
	sub = (char *)malloc(str_len - (size_t)start);
	if (sub == NULL)
		return (NULL);
	sub = (char *)ft_memmove(sub, s + start, len);
	return (sub);
}
