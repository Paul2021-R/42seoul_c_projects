/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:41:26 by haryu             #+#    #+#             */
/*   Updated: 2022/04/23 02:02:03 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	exception_lis_stack_2(t_pushlist **push)
{
	int	min;
	int	i;

	i = 0;
	min = find_minimun((*push)->array, (*push)->max_len, &i);
	align_stack_a(push, min, i);
	exit (0);
}

void	sort_stack_3(t_pushlist **push, int code, t_node *tmpa)
{
	if (code == 0)
	{
		if (tmpa->next->data > tmpa->next->next->data)
		{
			rra(push, 0);
			sa(push, 0);
		}
	}
	else if (code == 1)
	{
		if (tmpa->data > tmpa->next->next->data)
			ra(push, 0);
		else
			sa(push, 0);
	}
	else
	{
		if (tmpa->data > tmpa->next->data)
			sa(push, 0);
		rra(push, 0);
	}
	exit(0);
}

void	exception_lis_stack_3(t_pushlist **push)
{
	int		min;
	int		i;
	t_node	*tmpa;

	i = 0;
	min = find_minimun((*push)->array, (*push)->max_len, &i);
	(void)min;
	tmpa = (*push)->stack_a;
	sort_stack_3(push, i, tmpa);
	return ;
}

void	exception_lis(t_pushlist **push)
{
	if ((*push)->max_len <= 2)
		exception_lis_stack_2(push);
	else if ((*push)->max_len == 3)
		exception_lis_stack_3(push);
	return ;
}
