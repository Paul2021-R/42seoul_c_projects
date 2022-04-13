/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:57:57 by haryu             #+#    #+#             */
/*   Updated: 2022/04/14 01:30:28 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	lst_print(t_pushlist **stack, t_pushlist **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;

	tmp = (*stack)->integer;
	tmp2 = (*stack_b)->integer;
	ft_printf("======== 스택 ========\n");
	ft_printf("max_len : %d\n", (*stack)->max_len);
	ft_printf("----------------------\n");
	i = 0;
	while (i < (*stack)->max_len + 1)
	{
		printf("%-10d   ", tmp->content);
		if (i < (*stack_b)->max_len)
		{
			printf("%-10d", tmp2->content);
			tmp2 = tmp2->next;
		}
		printf("\n");
		tmp = tmp->next;
		i++;
	}
	printf("%-10s   %-10s\n","-", "-");
	printf("%-10s   %-10s\n", "A", "B");
	return ;
}
