/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:31:51 by haryu             #+#    #+#             */
/*   Updated: 2022/04/14 01:30:20 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	fill_stack(int *array, t_pushlist *stack_a, int ac)
{
	int		i;
	t_list	*tmp;
	t_list	*temp_a;

	stack_a->integer = ft_lstnew(0);
	temp_a = stack_a->integer;
	i = 0;
	while (i < ac)
	{
		tmp = ft_lstnew(array[i]);
		ft_lstadd_back(&temp_a, tmp);
		temp_a = temp_a->next;
		i++;
	}
	stack_a->max_len = ac - 1;
	return ;
}

void	fill_stack_empty(int code, t_pushlist *stack_b, int ac)
{
	stack_b->integer = ft_lstnew(code);
	stack_b->max_len = 1;
	return ;
}