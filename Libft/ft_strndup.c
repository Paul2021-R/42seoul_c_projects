/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:26:33 by haryu             #+#    #+#             */
/*   Updated: 2021/11/19 21:28:31 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(s1);
	if(!(dst = malloc(sizeof(char) *(len + 1))))
		return (NULL);
	ft_strlcpy(dst, s1, len + 1);
	return (dst);
}
