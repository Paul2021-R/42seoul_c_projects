/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:22:54 by haryu             #+#    #+#             */
/*   Updated: 2022/04/16 02:17:24 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	find_minimun(int *array, int max_len, int *index)
{
	int	ret;
	int	i;

	i = 0;
	*index = i;
	ret = array[i];
	while (++i < max_len)
		if (array[i] < ret)
		{
			ret = array[i];
			*index = i;
		}
	return (ret);
}

int	*array_malloc_to_zero(int length)
{
	int	*ret;
	int	i;

	ret = malloc(sizeof(int) * length);
	if (!ret)
		put_error();
	i = 0;
	while (i < length)
		ret[i++] = 0;
	return (ret);
}