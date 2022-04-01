/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:18:48 by haryu             #+#    #+#             */
/*   Updated: 2022/04/01 20:47:31 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	cli_error_print(int errorsign)
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

void	cli_print_intro(int ac)
{
	ft_printf("Client : How to use = ./client [SERVER PID] [sentences] ... \n");
	if (ac == 2)
	{
		ft_printf("Client : please, type messages for server.\n");
		exit (0);
	}
	if (ac > 2)
	{
		ft_printf("Client : PID is [ %d ]\n", getpid());
		return ;
	}
	exit(0);
}

void	initialize_signal(t_protocol *data, int code)
{
	if (code == 1)
	{
		data->index = 0;
		data->p = 0;
	}
	else if (code == 2)
	{
		data->printed = 0;
	}
	else
	{
		data->index = 0;
		data->p = 0;
		data->received_pid = 0;
		data->printed = 0;
	}
}