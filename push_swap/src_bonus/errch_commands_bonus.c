/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errch_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:43:07 by haryu             #+#    #+#             */
/*   Updated: 2022/04/23 16:49:52 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap_bonus.h"

void	error_commands(char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		return ;
	if (!ft_strncmp(str, "sb\n", 3))
		return ;
	if (!ft_strncmp(str, "ss\n", 3))
		return ;
	if (!ft_strncmp(str, "pa\n", 3))
		return ;
	if (!ft_strncmp(str, "pb\n", 3))
		return ;
	if (!ft_strncmp(str, "ra\n", 3))
		return ;
	if (!ft_strncmp(str, "rb\n", 3))
		return ;
	if (!ft_strncmp(str, "rr\n", 3))
		return ;
	if (!ft_strncmp(str, "rra\n", 4))
		return ;
	if (!ft_strncmp(str, "rrb\n", 4))
		return ;
	if (!ft_strncmp(str, "rrr\n", 4))
		return ;
	put_error();
}
