/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:57:57 by haryu             #+#    #+#             */
/*   Updated: 2022/04/14 16:56:13 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include <stdio.h>

void	lst_print(t_pushlist **push)
{
	t_list		*tmpa;
	t_list		*tmpb;
	int			i;

	tmpa = (*push)->stack_a;
	tmpb = (*push)->stack_b;
	ft_printf("======== 스택 ========\n");
	ft_printf("max_len : %d\n", (*push)->max_len);
	ft_printf("----------------------\n");
	i = 0;
	while (i < (*push)->max_len)
	{
		printf("%-10p   ", ((int *)(tmpa->content)));
		if ((int *)(tmpb->content))
		{
			printf("%-10p", ((int *)(tmpb->content)));
			tmpb = tmpb->next;
		}
		printf("\n");
		tmpa = tmpa->next;
		i++;
	}
	printf("%-10s   %-10s\n", "-", "-");
	printf("%-10s   %-10s\n", "A", "B");
	return ;
}
