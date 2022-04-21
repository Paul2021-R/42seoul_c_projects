/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:35:49 by haryu             #+#    #+#             */
/*   Updated: 2022/04/21 18:07:50 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	final_lis(int *array, int **record, int **ret, int max_len)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while(++i < max_len)
	{
		if (j < (*record)[i])
			j = (*record)[i];
	}
	i = max_len;
	(*ret)[0] = array[0];
	while (--i >= 0)
	{
		if ((*record)[i] == j)
		{
			(*ret)[j] = array[i];
			j--;
		}
	}
	for(int i = 0; i < max_len; i++)
		printf("[%d] %d\n", i, (*ret)[i]);
}

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
	int	*record;

	record = array_malloc_to_zero(max_len);
	i = ref_i;
	record[0] = 0;
	j = 1;
	while (++i < max_len)
	{
		if ((*ret)[j - 1] < array[i])
		{
			(*ret)[j] = array[i];
			record[i] = j++;
		}
		else
		{
			pos = lower_bound((*ret), array[i], 0, j);
			(*ret)[pos] = array[i];
			record[i] = pos;
		}
	}
	for(int i = 0; i < max_len; i++)
		printf("record[%d]: %d\n", i, record[i]);
	final_lis(array, &record, ret, max_len);
	free(record);
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
	align_stack_a(push, pivot, i);
	lst_print(push);
	array_copy_from_stack(push);
	(*push)->lis_len = (*push)->max_len;
	lis_arr = array_malloc_to_zero((*push)->max_len);
	make_lis((*push)->array, &lis_arr, 0, (*push)->max_len);
	lis_print(push);
	free((*push)->array);
	(*push)->array = lis_arr;
	(*push)->lis_len = find_lis_len((*push)->array, (*push)->lis_len);
	return ;
}
