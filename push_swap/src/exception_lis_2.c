/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_lis_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:05:01 by haryu             #+#    #+#             */
/*   Updated: 2022/04/23 12:22:13 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	exception_sort_b_2(t_pushlist **push, int code)
{
	t_node	*tmpb;

	tmpb = (*push)->stack_b;
	if (code == 0)
	{
		if (tmpb->next->data < tmpb->next->next->data)
		{
			rb(push, SPE);
			sb(push, SPE);
		}
		else
			rb(push, SPE);
	}
	else if (code == 1)
	{
		rrb(push, SPE);
		tmpb = (*push)->stack_b;
		if (tmpb->data < tmpb->next->data)
			sb(push, SPE);
	}
	else
		if (tmpb->data < tmpb->next->data)
			sb(push, SPE);
}

void	exception_sort_b(t_pushlist **push)
{
	t_node	*tmpb;
	int		min;
	int		i;

	tmpb = (*push)->stack_b;
	min = ft_push_min(tmpb);
	i = where_is_node(tmpb, min);
	exception_sort_b_2(push, i);
}

void	exception_sort_a(t_pushlist **push, int min)
{
	if ((*push)->stack_a->data == min)
	{
		ra(push, SPE);
		pa(push);
		pa(push);
		pa(push);
		rra(push, SPE);
	}
	else
	{
		pa(push);
		pa(push);
		pa(push);
		rra(push, SPE);
	}
}

void	exception_lis_2(t_pushlist **push)
{
	int		i;
	int		min;
	int		max;
	t_node	*tmpa;

	i = 0;
	min = find_minimun((*push)->array, (*push)->max_len, &i);
	max = ft_push_max((*push)->stack_a);
	while (1)
	{
		tmpa = (*push)->stack_a;
		if (tmpa->data == min || tmpa->data == max)
			ra(push, SPE);
		else
			pb(push);
		if ((*push)->max_len == 2)
			break ;
	}
	exception_sort_b(push);
	exception_sort_a(push, min);
	check_already_done(push);
}
