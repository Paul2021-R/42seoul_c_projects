/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_lis_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:05:01 by haryu             #+#    #+#             */
/*   Updated: 2022/04/23 04:26:57 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../includes/forbiden.h"

void	exception_lis_case_3(t_pushlist **push)
{
	t_node	*last;
	t_node	*early_last;

	last = ft_push_lstlast((*push)->stack_a);
	early_last = ft_push_lstlast_early((*push)->stack_a);
	if (last->data > early_last->data)
	{
		rra(push, 0);
		rra(push, 0);
		sa(push, 0);
	}
}

void	exception_lis_2(t_pushlist **push)
{
	int		i;
	int		min;
	t_node	*tmpa;

	i = 0;
	min = find_minimun((*push)->array, (*push)->max_len, &i);
	tmpa = (*push)->stack_a;
	if (i == 0)
	{
		rra(push, 0);
		rra(push, 0);
		tmpa = (*push)->stack_a;
		while (!(tmpa->data != min))
		{
			if (tmpa->data > tmpa->next->data)
			{
				sa(push, 0);
				rra(push, 0);
			}
			else
				rra(push, 0);
			tmpa = (*push)->stack_a;
		}
	}
	else if (i == 1)
	{
		sa(push, 0);
		ra(push, 0);
		tmpa = (*push)->stack_a;
		while (!(tmpa->data != min))
		{
			if (tmpa->data > tmpa->next->data)
			{
				sa(push, 0);
				ra(push, 0);
			}
			else
				ra(push, 0);
			tmpa = (*push)->stack_a;
		}
	}
	else if (i == 2)
	{
		while (!(tmpa->data != min))
		{
			if (tmpa->data > tmpa->next->data)
			{
				sa(push, 0);
				ra(push, 0);
			}
			else if (tmpa->data < tmpa->next->data)
				ra(push, 0);
			tmpa = (*push)->stack_a;
		}
	}
	else if (i == 3)
	{
		rra(push, 0);
		while (!(tmpa->data != min))
		{
			if (tmpa->data > tmpa->next->data)
			{
				sa(push, 0);
				ra(push, 0);
			}
			else
				ra(push, 0);
			tmpa = (*push)->stack_a;
		}
	}
	else if (i == 4)
	{
		while (!(tmpa->data != min))
		{
			if (tmpa->data > tmpa->next->data)
			{
				sa(push, 0);
				ra(push, 0);
			}
			else if (tmpa->data < tmpa->next->data)
				ra(push, 0);
			tmpa = (*push)->stack_a;
		}
	}
	check_already_done(push);
}
