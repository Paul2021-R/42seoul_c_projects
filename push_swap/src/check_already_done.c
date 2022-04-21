/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_already_done.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:24:29 by haryu             #+#    #+#             */
/*   Updated: 2022/04/21 21:49:54 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	check_already_done(t_pushlist **push)
{
	int		check;
	int		i;
	t_node	*tmpa;

	check = 0;
	i = 0;
	if ((*push)->len_b == 0)
		check += 1;
	tmpa = (*push)->stack_a;
	while (i < (*push)->max_len)
	{
		if (tmpa->data < tmpa->next->data)
		{
			tmpa = tmpa->next;
			if (tmpa->next == NULL)
			{
				check += 1;
				break ;
			}
		}
		else
			check -= 1;
		i++;
	}
	if (check == 2)
		exit(0);
	return ;
}