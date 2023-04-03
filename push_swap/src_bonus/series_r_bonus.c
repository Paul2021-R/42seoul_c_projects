/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   series_r_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:30:51 by haryu             #+#    #+#             */
/*   Updated: 2022/04/24 19:06:58 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap_bonus.h"

void	ra(t_pushlist **push, int code)
{
	t_node	*tmp_1;
	t_node	*tmp_last;
	int		stack;

	stack = ft_push_lstsize((*push)->stack_a);
	if (stack == 1)
		return ;
	tmp_1 = (*push)->stack_a;
	(*push)->stack_a = tmp_1->next;
	tmp_last = ft_push_lstlast((*push)->stack_a);
	tmp_last->next = tmp_1;
	tmp_1->next = NULL;
	if (code == 0)
		ft_printf("ra\n");
	return ;
}

void	rb(t_pushlist **push, int code)
{
	t_node	*tmp_1;
	t_node	*tmp_last;

	if ((*push)->len_b <= 1)
		return ;
	tmp_1 = (*push)->stack_b;
	(*push)->stack_b = tmp_1->next;
	tmp_last = ft_push_lstlast((*push)->stack_b);
	tmp_last->next = tmp_1;
	tmp_1->next = NULL;
	if (code == 0)
		ft_printf("rb\n");
	return ;
}

void	rr(t_pushlist **push)
{
	ra(push, ALL);
	rb(push, ALL);
	return ;
}
