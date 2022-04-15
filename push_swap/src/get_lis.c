/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:35:49 by haryu             #+#    #+#             */
/*   Updated: 2022/04/16 02:17:51 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	lower_bound(int *array, int value, int s, int e)
{
	int	mid;

	while (s < e)
	{
		mid = s + (e - s) / 2;
		if (value <= array[mid])
			e = mid;
		else
			s = mid + 1;
	}
	return (s);
}

void	make_lis(int *array, int **ret, int ref_i, int max_len)
{
	int	i;
	int	j;
	int	pos;

	i = ref_i;
	j = 1;
	while (++i < max_len)
	{
		if ((*ret)[j - 1] < array[i])
			(*ret)[j++] = array[i];
		else
		{
			pos = lower_bound((*ret), array[i], 0, j);
			(*ret)[pos] = array[i];
		}
	}
}

int	find_lis_len(int *array, int max_len)
{
	int	ret;

	ret = 0;
	while (ret < max_len)
	{
		if (array[ret] == 0 && array[ret + 1] == 0)
			break ;
		if (array[ret] == 0 && ret + 1 == max_len)
			break ;
		ret++;
	}
	return (ret);
}

void	get_lis(t_pushlist **push)
{
	int	*lis_arr;
	int	i;
	int	pivot;

	pivot = find_minimun((*push)->array, (*push)->max_len, &i);
	pivot = (*push)->max_len - i;
	lis_arr = array_malloc_to_zero(pivot);
	(*push)->lis_len = pivot;
	lis_arr[0] = (*push)->array[i];
	make_lis((*push)->array, &lis_arr, i, (*push)->max_len);
	free((*push)->array);
	(*push)->array = lis_arr;
	(*push)->lis_len = find_lis_len((*push)->array, (*push)->lis_len);
	return ;
}
