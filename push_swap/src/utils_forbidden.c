/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_forbidden.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:57:57 by haryu             #+#    #+#             */
/*   Updated: 2022/04/16 00:18:59 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include <stdio.h>

void	lst_print(t_pushlist **push)
{
	t_node		*tmpa;
	t_node		*tmpb;
	int			len_a;
	int			len_b;

	tmpa = (*push)->stack_a;
	tmpb = (*push)->stack_b;
	len_a = (*push)->max_len;
	len_b = (*push)->len_b;
	printf("\nlen a : %d          len b : %d\n", len_a, len_b);
	while (len_a + len_b)
	{
		if (!len_a)
			printf("           ");
		if (len_a)
		{
			printf("%-10d ", tmpa->data);
			if (len_b == 0)
				printf("\n");
			tmpa = tmpa->next;
			len_a--;
		}
		if (len_b)
		{
			printf("          %-10d\n", tmpb->data);
			tmpb = tmpb->next;
			len_b--;
		}
	}
	ft_printf("%s          ", "stack A");
	ft_printf("%s\n\n", "stack B");
	return ;
}

void	lis_print(t_pushlist **push)
{
	for (int i = 0; i < (*push)->lis_len; i++)
	{
		ft_printf("lis_arr[%d] : %d\n", i, (*push)->array[i]);
	}
	ft_printf("lis len = %d\n", (*push)->lis_len);
	return ;
}
