/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:35:49 by haryu             #+#    #+#             */
/*   Updated: 2022/04/18 21:36:45 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	final_lis(int *array, int **record, int **ret, int max_len)
{
	int	i;
	int	j;
	int	max_num;

	i = 0;
	max_num = 0;
	while (i < max_len)
	{
		if (max_num < (*record)[i])
			max_num = (*record)[i];
		i++;
	}
	j = 0;
	while (--i >= 0)
	{
		if (max_num == (*record)[i])
		{
			(*ret)[j++] = array[i];
			max_num--;
		}
	}
	i = 1;
	(*record)[0] = array[0];
	while (i < max_len)
	{
		j = 0;
		while ((*ret)[j] != array[0])
		{
			if ((*ret)[j] == array[i])
			{
				(*record)[i] = array[i];
				break ;
			}
			j++;
		}
		i++;
	}
	return ;
}
/*
	현재 문제 사항
	진짜 LIS 배열을 만들기 위하여 LIS 레코드를 기록. 이를 활용해서 ret에 배열넣는 것 까진 가능했다. 
	하지만 문제는 거꾸로 들어가 있는 상황인지라, 해당 상황을 어떻게 개선해야할지 감이 안옴. 
	현재 아이디어, 거꾸로 넣기 시작해서 array[0] 값이 나오기 전까지 스킵 + 이후 입력형태로 하면 될 것으로 판단된다. 
	조건은 현재의 i == arr[0] i+1 != arr[0] 이면 될듯! 
*/ 

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
			//(*ret)[j] = array[i];
			record[i] = j++;
		}
		else
		{
			pos = lower_bound((*ret), array[i], 0, j);
			//(*ret)[pos] = array[i];
			record[i] = pos;
		}
	}
	final_lis(array, &record, ret, max_len);
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
	(*push)->lis_len = (*push)->max_len;
	lis_print(push);
	lis_arr = array_malloc_to_zero((*push)->max_len);
	(*push)->lis_len = (*push)->max_len;
	lis_arr[0] = pivot;
	make_new_array(push, pivot);
	lis_print(push);
	make_lis((*push)->array, &lis_arr, 0, (*push)->max_len);
	free((*push)->array);
	(*push)->array = lis_arr;
	(*push)->lis_len = find_lis_len((*push)->array, (*push)->lis_len);
	return ;
}
