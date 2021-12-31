/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 03:26:04 by haryu             #+#    #+#             */
/*   Updated: 2022/01/01 03:35:19 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr_len(const char *str)
{
	char	*tmp;

	tmp = (char *)str;
	if (!tmp)
		return (-1);
	ft_putstr(tmp);
	return ((int)ft_strlen(tmp));
}
