/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_already_done_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:24:29 by haryu             #+#    #+#             */
/*   Updated: 2022/04/23 17:31:47 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap_bonus.h"

int	check_score_already_done(t_node *tmpa, int max_len)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < max_len)
	{
		if (tmpa->data < tmpa->next->data)
		{
			tmpa = tmpa->next;
			if (tmpa->next == NULL)
			{
				ret += 1;
				break ;
			}
		}
		else
			ret -= 1;
		i++;
	}
	return (ret);
}

void	check_already_done_bonus(t_pushlist **push)
{
	int		check;
	t_node	*tmpa;

	check = 0;
	if ((*push)->len_b == 0)
		check += 1;
	if ((*push)->max_len == 1)
	{
		ft_printf("OK\n");
		exit(0);
	}
	tmpa = (*push)->stack_a;
	check += check_score_already_done(tmpa, (*push)->max_len);
	if (check == 2)
	{
		ft_printf("OK\n");
		exit(0);
	}
	ft_printf("KO\n");
}
