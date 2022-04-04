/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_old_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:59:07 by haryu             #+#    #+#             */
/*   Updated: 2022/04/04 19:20:19 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_protocol g_server;

void	ser_initialize_server(void)
{
	ft_printf("Server : Server is activated.\n\
Server : Server's PID is [ %d ]\n", getpid());
	ft_printf("Server : Please connect a client to server.\n");
	initialize_signal(&g_server);
	return ;
}

void	ser_sighandler_connect_ready(int signo, siginfo_t *info, void *data)
{
	int ret;

	(void)data;
	if (g_server.received_pid == 0)
		g_server.received_pid = info->si_pid;
	else if (g_server.received_pid != 0)
	{
		ser_initialize_server();
		g_server.received_pid = info->si_pid;
	}
	ft_printf("Server : Client is Connected.\n\
Server : Client PID is [%d]\n", g_server.received_pid);
	ret = kill(g_server.received_pid, SIGUSR2);
	if (ret)
		error_print(ret, 0);
	return ;
}

void	ser_sighandler_receive_data(int signo, siginfo_t *info, void *data)
{
	(void)data;
	if (g_server.received_pid != info->si_pid)
	{
		kill(info->si_pid, SIGUSR1);
	}
	signo -= SIGUSR1;
	g_server.p = g_server.p << 1 | signo;
	g_server.index++;
	if (g_server.index == 8)
	{
		write(1, &g_server.p, 1);
		g_server.index = 0;
		if (g_server.p == '\0')
		{
			initialize_signal(&g_server);
			g_server.printed = 1;
		}
	}
	kill(g_server.received_pid, SIGUSR2);
	return ;
}

int	ser_recieve_char(void)
{
	int					i;
	struct sigaction	sa_print;

	sa_print.sa_sigaction = ser_sighandler_receive_data;
	sa_print.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_print.sa_mask);
	sigaddset(&sa_print.sa_mask, SIGUSR1);
	sigaddset(&sa_print.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa_print, NULL);
	sigaction(SIGUSR2, &sa_print, NULL);
	i = 0;
	while (1)
	{
		// ft_printf("check?!");
		if (i == 7)
		{
			kill(g_server.received_pid, SIGUSR2);
			i = -1;
			g_server.p = 0;
			ft_printf("\ncheck!!\n");
		}
		pause();
		kill(g_server.received_pid, SIGUSR2);
		if (g_server.printed == 1)
		{
			/**/
		}
		i++;
	}
	return (0);
}

int main(void)
{
	struct sigaction	sa_pre;

	ser_initialize_server();
	ser_
	sa_pre.sa_sigaction = ser_sighandler_connect_ready;
	sa_pre.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_pre.sa_mask);
	sigaddset(&sa_pre.sa_mask, SIGUSR1);
	sigaddset(&sa_pre.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa_pre, NULL);
	sigaction(SIGUSR2, &sa_pre, NULL);
	pause();
	while(1)
	{
		ser_recieve_char();
		pause();
	}
	return (0);
}