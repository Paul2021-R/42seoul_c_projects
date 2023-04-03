/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   series_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:16:39 by haryu             #+#    #+#             */
/*   Updated: 2022/04/16 00:14:12 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sa(t_pushlist **push, int code)
{
	t_node	*tmp;

	tmp = (*push)->stack_a->next;
	(*push)->stack_a->next = tmp->next;
	tmp->next = (*push)->stack_a;
	(*push)->stack_a = tmp;
	if (code == 0)
		ft_printf("sa\n");
	return ;
}

void	sb(t_pushlist **push, int code)
{
	t_node	*tmp;

	tmp = (*push)->stack_b->next;
	(*push)->stack_b->next = tmp->next;
	tmp->next = (*push)->stack_b;
	(*push)->stack_b = tmp;
	if (code == 0)
		ft_printf("sb\n");
	return ;
}

void	ss(t_pushlist **push)
{
	sa(push, ALL);
	sb(push, ALL);
	ft_printf("ss\n");
	return ;
}
