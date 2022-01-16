/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:35:30 by haryu             #+#    #+#             */
/*   Updated: 2022/01/16 14:46:18 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_chartostr(char c)
{
	char	*ret;

	ret = (char *)ft_calloc(2, sizeof(char));
	if (!ret || !c)
		return (NULL);
	ret[0] = c;
	return (ret);
}
