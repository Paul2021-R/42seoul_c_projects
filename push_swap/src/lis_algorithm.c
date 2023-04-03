/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:05:24 by haryu             #+#    #+#             */
/*   Updated: 2022/04/23 12:16:24 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	action_same(int *action_a, int *action_b)
{
	int	ret;

	ret = 0;
	while ((*action_a) > 0 && (*action_b) > 0)
	{
		ret++;
		(*action_a)--;
		(*action_b)--;
	}
	while ((*action_a) < 0 && (*action_b) < 0)
	{
		ret--;
		(*action_a)++;
		(*action_b)++;
	}
	return (ret);
}

void	do_same(int same, t_pushlist **push)
{
	if (same == 0)
		return ;
	while (same > 0)
	{
		rr(push);
		same--;
	}
	while (same < 0)
	{
		rrr(push);
		same++;
	}
	return ;
}

void	do_a(int action_a, t_pushlist **push)
{
	if (action_a == 0)
		return ;
	while (action_a > 0)
	{
		ra(push, 0);
		action_a--;
	}
	while (action_a < 0)
	{
		rra(push, 0);
		action_a++;
	}
	return ;
}

void	do_b(int action_b, t_pushlist **push)
{
	if (action_b == 0)
		return ;
	while (action_b > 0)
	{
		rb(push, 0);
		action_b--;
	}
	while (action_b < 0)
	{
		rrb(push, 0);
		action_b++;
	}
	return ;
}

void	lis_algorithm(t_pushlist **push, int value)
{
	int		action_a;
	int		action_b;
	int		same;
	int		i;
	t_node	*tmpb;

	i = 0;
	tmpb = (*push)->stack_b;
	while (i < value)
	{
		tmpb = tmpb->next;
		i++;
	}
	action_a = check_score_a((*push)->stack_a, tmpb->data);
	action_b = check_score_b((*push)->stack_b, tmpb->data, (*push)->len_b);
	same = action_same(&action_a, &action_b);
	do_same(same, push);
	do_a(action_a, push);
	do_b(action_b, push);
	pa(push);
	return ;
}
