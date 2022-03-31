/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:18:48 by haryu             #+#    #+#             */
/*   Updated: 2022/03/31 22:34:30 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_print(int errorsign)
{
	if (errno == EPERM)
		ft_printf("Client : You don't have a permission to send a signal.\n");
	else if (errno == ESRCH)
		ft_printf("Client : Please check server pid.\n");
	else
		ft_printf("Client : You have an error to send signals.\n");
	exit (1);
	return ;
}

void	print_intro(int ac)
{
	ft_printf("Client : How to use = ./a.out [Pid] [sentences] ... \n");
	if (ac == 2)
		ft_printf("Client : please, type messages for server.\n");
	if (ac > 2)
	{
		ft_printf("Client : PID is %d\n", getpid());
		return ;
	}
	exit(0);
}