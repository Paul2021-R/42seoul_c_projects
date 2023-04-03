/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_core_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:09:18 by haryu             #+#    #+#             */
/*   Updated: 2022/04/23 17:31:48 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap_bonus.h"

void	do_command(t_pushlist **push, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(push, ALL);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		sb(push, ALL);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(push);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(push);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(push);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(push, ALL);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(push, ALL);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(push);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(push, ALL);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(push, ALL);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(push);
}

void	do_pre_commands(t_pushlist **push, t_list *commands)
{
	int	limit;
	int	i;

	i = 0;
	limit = ft_lstsize(commands);
	while (i < limit)
	{
		do_command(push, (char *)(commands->content));
		i++;
		commands = commands->next;
	}
	check_already_done_bonus(push);
}
