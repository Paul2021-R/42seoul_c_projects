/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:31:51 by haryu             #+#    #+#             */
/*   Updated: 2022/04/14 00:53:11 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	fill_stack(int *array, t_pushlist *stack_a, int ac)
{
	int		i;
	t_list	*tmp;
	t_list	*temp_a;

	i = 0;
	stack_a->integer = ft_lstnew(array[i]);
	temp_a = stack_a->integer;
	while (++i < ac - 1)
	{
		tmp = ft_lstnew(array[i]);
		ft_lstadd_back(&temp_a, tmp);
		temp_a = temp_a->next;
	}
	stack_a->max_len = ac - 1;
	return ;
}

void	fill_stack_empty(int code, t_pushlist *stack_b, int ac)
{
	int		i;
	t_list	*tmp;
	t_list	*temp_b;

	i = 0;
	stack_b->integer = ft_lstnew(code);
	temp_b = stack_b->integer;
	while (++i < ac - 1)
	{
		tmp = ft_lstnew(code);
		ft_lstadd_back(&temp_b, tmp);
		temp_b = temp_b->next;
	}
	stack_b->max_len = ac - 1;
	return ;
}