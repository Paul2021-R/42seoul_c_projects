/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:05:59 by haryu             #+#    #+#             */
/*   Updated: 2022/04/05 00:16:06 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mandatory/server.h"

t_protocol	g_server;

void	ser_sighandler_pre(int signo, siginfo_t *info, void *data)
{
	(void)data;
	if (signo == SIGUSR1)
	{
		g_server.received_pid = info->si_pid;
		ft_printf("Server : Connection is ready. \
Client PID is [ %d ]\n", g_server.received_pid);
		kill(g_server.received_pid, SIGUSR1);
	}
	return ;
}

void	ser_sighandler_char(int signo, siginfo_t *info, void *data)
{
	(void)data;
	(void)info;
	if (signo == SIGUSR1)
	{
		ft_printf("Server : Start receiving data.\n");
		usleep(1000);
		kill(g_server.received_pid, SIGUSR1);
	}
	return ;
}

void	ser_sighandler_bit(int signo, siginfo_t *info, void *data)
{
	int	bit;

	(void)data;
	bit = signo - SIGUSR1;
	if (g_server.received_pid != info->si_pid)
	{
		kill(info->si_pid, SIGUSR2);
		return ;
	}
	g_server.p = g_server.p << 1 | bit;
	if (g_server.index == 7)
		write(1, &g_server.p, 1);
	if (g_server.p == 0 && g_server.index == 7)
		g_server.printed = 1;
	g_server.index++;
	usleep(500);
	kill(g_server.received_pid, SIGUSR1);
	return ;
}

void	ser_receiving_char(void)
{
	sigaction(SIGUSR1, &g_server.sa_char, NULL);
	sigaction(SIGUSR2, &g_server.sa_char, NULL);
	pause();
	while (1)
	{
		ser_receiving_bit();
		if (g_server.printed == 1)
			break ;
	}
	kill(g_server.received_pid, SIGUSR2);
}

int	main(void)
{
	ser_initialize_server();
	ser_sigaction_initialize(&g_server.sa_pre, &ser_sighandler_pre);
	ser_sigaction_initialize(&g_server.sa_char, &ser_sighandler_char);
	ser_sigaction_initialize(&g_server.sa_bit, &ser_sighandler_bit);
	while (1)
	{
		ser_initialize_signal(&g_server);
		ser_connection_ready();
		ser_receiving_char();
		ft_printf("\n");
	}
	return (0);
}
