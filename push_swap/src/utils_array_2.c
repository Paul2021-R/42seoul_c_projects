/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_array_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:44:18 by haryu             #+#    #+#             */
/*   Updated: 2022/04/20 18:59:57 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	array_copy_from_stack(t_pushlist **push)
{
	t_node	*tmpa;
	int		i;

	tmpa = (*push)->stack_a;
	i = 0;
	while(tmpa)
	{
		(*push)->array[i] = tmpa->data;
		tmpa = tmpa->next;
		i++;
	}
	return ;
}
