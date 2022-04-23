/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   series_rr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:07:16 by haryu             #+#    #+#             */
/*   Updated: 2022/04/23 17:22:46 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	rra(t_pushlist **push, int code)
{
	t_node	*tmp_end;
	t_node	*tmp_before_end;

	tmp_end = ft_push_lstlast((*push)->stack_a);
	tmp_before_end = ft_push_lstlast_early((*push)->stack_a);
	tmp_end->next = (*push)->stack_a;
	(*push)->stack_a = tmp_end;
	tmp_before_end->next = NULL;
	if (code == 0)
		ft_printf("rra\n");
	return ;
}

void	rrb(t_pushlist **push, int code)
{
	t_node	*tmp_end;
	t_node	*tmp_before_end;

	(void)code;
	(void)tmp_before_end;
	tmp_end = ft_push_lstlast((*push)->stack_b);
	tmp_before_end = ft_push_lstlast_early((*push)->stack_b);
	tmp_end->next = (*push)->stack_b;
	(*push)->stack_b = tmp_end;
	tmp_before_end->next = NULL;
	if (code == 0)
		ft_printf("rrb\n");
	return ;
}

void	rrr(t_pushlist **push)
{
	rra(push, ALL);
	rrb(push, ALL);
	return ;
}
