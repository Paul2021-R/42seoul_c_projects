/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_array_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:22:54 by haryu             #+#    #+#             */
/*   Updated: 2022/04/24 16:55:25 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap_bonus.h"

int	find_minimun(int *array, int max_len, int *index)
{
	int	ret;
	int	i;

	i = 0;
	*index = i;
	ret = array[i];
	while (++i < max_len)
	{
		if (array[i] < ret)
		{
			ret = array[i];
			*index = i;
		}
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

void	align_stack_a(t_pushlist **push, int min_value, int min_pos)
{
	t_node	*tmpa;

	if (min_pos <= (*push)->max_len / 2)
	{
		while ((*push)->stack_a)
		{
			if ((*push)->stack_a->data == min_value)
				return ;
			ra(push, 0);
		}
	}
	else
	{
		while ((*push)->stack_a)
		{
			tmpa = (*push)->stack_a;
			if ((*push)->stack_a->data == min_value)
				return ;
			if (tmpa->data > tmpa->next->data)
				sa(push, 0);
			rra(push, 0);
		}
	}	
}

int	where_is_node(t_node *stack, int target)
{
	t_node	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (tmp->data == target)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	array_copy_from_stack(t_pushlist **push)
{
	t_node	*tmpa;
	int		i;

	tmpa = (*push)->stack_a;
	i = 0;
	while (tmpa)
	{
		(*push)->array[i] = tmpa->data;
		tmpa = tmpa->next;
		i++;
	}
	return ;
}
