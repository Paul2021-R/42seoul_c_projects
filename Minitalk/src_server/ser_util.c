/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ser_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:33:11 by haryu             #+#    #+#             */
/*   Updated: 2022/04/05 00:16:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mandatory/server.h"

t_protocol	g_server;

void	ser_initialize_server(void)
{
	ft_printf("Server : Server is activated.\n\
Server : Server's PID is [ %d ]\n", getpid());
	ft_printf("Server : Please connect a client to server.\n");
	return ;
}

void	ser_initialize_signal(t_protocol *data)
{
	data->received_pid = 0;
	data->printed = 0;
	data->index = 0;
	data->p = 0;
}

void	ser_sigaction_initialize(struct sigaction *sa, \
void (*f)(int, siginfo_t *, void *))
{
	sa->sa_sigaction = f;
	sa->sa_flags = SA_SIGINFO;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGUSR1);
	sigaddset(&sa->sa_mask, SIGUSR2);
	return ;
}

void	ser_receiving_bit(void)
{
	sigaction(SIGUSR1, &g_server.sa_bit, NULL);
	sigaction(SIGUSR2, &g_server.sa_bit, NULL);
	while (1)
	{
		pause();
		if (g_server.index == 8)
		{
			g_server.index = 0;
			g_server.p = 0;
			kill(g_server.received_pid, SIGUSR1);
		}
		if (g_server.printed == 1)
		{
			break ;
		}
	}
}

void	ser_connection_ready(void)
{
	sigaction(SIGUSR1, &g_server.sa_pre, NULL);
	sigaction(SIGUSR2, &g_server.sa_pre, NULL);
	pause();
	return ;
}
