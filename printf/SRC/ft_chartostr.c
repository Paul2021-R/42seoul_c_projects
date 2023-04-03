/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:35:30 by haryu             #+#    #+#             */
/*   Updated: 2022/01/20 21:03:50 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_chartostr(char c)
{
	char	*ret;

	ret = (char *)ft_calloc(sizeof(char *), 2);
	if (!ret)
		return (NULL);
	if (c == '\0')
		ret[0] = '\0';
	ret[0] = c;
	return (ret);
}
