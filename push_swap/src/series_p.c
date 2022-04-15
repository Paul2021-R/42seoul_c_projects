/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   series_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:46:02 by haryu             #+#    #+#             */
/*   Updated: 2022/04/15 23:40:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	pb(t_pushlist **push)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_a = (*push)->stack_a->next;
	tmp_b = (*push)->stack_b;
	(*push)->stack_b = (*push)->stack_a;
	(*push)->stack_a = tmp_a;
	if ((*push)->len_b == 0)
		(*push)->stack_b->next = NULL;
	else if ((*push)->len_b > 0)
		(*push)->stack_b->next = tmp_b;
	(*push)->max_len--;
	(*push)->len_b++;
	ft_printf("pb\n");
	return ;
}

void	pa(t_pushlist **push)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_a = (*push)->stack_a;
	tmp_b = (*push)->stack_b->next;
	(*push)->stack_a = (*push)->stack_b;
	(*push)->stack_b = tmp_b;
	if ((*push)->max_len == 0)
		(*push)->stack_a->next = NULL;
	else if ((*push)->max_len != 0)
		(*push)->stack_a->next = tmp_a;
	(*push)->max_len++;
	(*push)->len_b--;
	ft_printf("pa\n");
	return ;
}