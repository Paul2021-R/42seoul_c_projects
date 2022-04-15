/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:31:51 by haryu             #+#    #+#             */
/*   Updated: 2022/04/15 23:05:17 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	fill_stack(t_pushlist **push, int ac)
{
	int		i;
	t_node	*tmp;
	t_node	*tmp_a;

	i = 0;
	(*push)->stack_a = ft_push_lstnew((*push)->array[i]);
	tmp_a = (*push)->stack_a;
	while (++i < ac - 1)
	{
		tmp = ft_push_lstnew((*push)->array[i]);
		ft_push_lstadd_back(&tmp_a, tmp);
		tmp_a = tmp_a->next;
	}
	(*push)->len_b = 0;
	return ;
}
