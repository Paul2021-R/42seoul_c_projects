/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 02:57:50 by haryu             #+#    #+#             */
/*   Updated: 2021/11/10 12:46:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	ret;

	ret = 0;
	if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
		ret = 1;
	else
		ret = 0;
	return (ret);
}