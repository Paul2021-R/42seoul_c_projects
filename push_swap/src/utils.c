/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:57:57 by haryu             #+#    #+#             */
/*   Updated: 2022/04/15 09:00:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include <stdio.h>

void	lst_stack_print(t_node *stack_a, t_node *stack_b, int len_a, int len_b)
{
	int	i;

	i = 0;
	while (i < len_a)
	{
		printf("          %-10d   ", stack_a->data);
		if (i < len_b)
		{
			printf("          %-10d", stack_b->data);
			stack_b = stack_b->next;
		}
		printf("\n");
		stack_a = stack_a->next;
		i++;
	}
}

void	lst_print(t_pushlist **push)
{
	t_node		*tmpa;
	t_node		*tmpb;
	int			len_a;
	int			len_b;

	tmpa = (*push)->stack_a;
	tmpb = (*push)->stack_b;
	len_a = ft_push_lstsize((*push)->stack_a);
	len_b = 0;
	if ((*push)->len_b)
		len_b = ft_push_lstsize((*push)->stack_b);
	ft_printf("--------------------------------------------\n\
max_len : \
%d\n--------------------\
------------------------\n", (*push)->max_len);
	lst_stack_print(tmpa, tmpb, len_a, len_b);
	printf("--------------------------------------------\n          %-10s \
            %-10s\n          %-10s             %-10s\n", "-", "-", "A", "B");
	return ;
}
