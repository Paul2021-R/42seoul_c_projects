/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:10:59 by haryu             #+#    #+#             */
/*   Updated: 2022/04/04 16:23:20 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_protocol	g_server;

void	ser_signal_print(void)
{
	static char		*result;
	char			*temporary;
	char			bitchar[2];

	bitchar[1] = '\0';
	bitchar[0] = g_server.p;
	if (bitchar[0] == '\0')
	{
		ft_printf("%s", result);
		free(result);
		initialize_signal(&g_server, 0);
		g_server.printed = 1;
		result = 0;
		return ;
	}
	if (result == 0)
	{
		result = (char *)malloc (sizeof(char) * 2);
		if (!result)
		{
			ft_printf("Server : Malloc allocation is failed. Please check.\n");
			exit(0);
		}
		result[1] = '\0';
	}
	temporary = result;
	result = ft_strjoin(temporary, bitchar);
	//free(temporary);
	return ;
}

void	ser_initialize_server(void)
{
	ft_printf("Server : Server is activated. Server's PID is [ %d ]\n", getpid());
	ft_printf("Server : Please connect a client to server.\n");
	initialize_signal(&g_server);
	return ;
}

void	ser_sighandler_socket_ready(int signo, siginfo_t *info, void *data)
{
	(void)data;
	if (signo == SIGUSR2 && g_server.received_pid == 0)
	{
		ft_printf("Server : Client is connected.\n");
		g_server.received_pid = info->si_pid;
	}
	else if (signo == SIGUSR2 && g_server.received_pid == info->si_pid)
	{
		g_server.received_pid = info->si_pid;
		g_server.printed = 0;
	}
	else if (signo == SIGUSR2 && g_server.received_pid != info->si_pid)
	{
		ft_printf("Server : Another Client is connected. Erase old data.\n");
		initialize_signal(&g_server, 0);
		g_server.received_pid = info->si_pid;
	}
	kill(info->si_pid, SIGUSR2);
	return ;
}

void	ser_sighandler_receive_data(int signo, siginfo_t *info, void *data)
{
	(void)data;
	signo -= SIGUSR1;
	g_server.p = g_server.p <<1 | signo;
	g_server.index++;
	if (g_server.index == 8)
	{
		ser_signal_print();
		initialize_signal(&g_server, 1);
	}
	kill(info->si_pid, SIGUSR2);
	return ;
}

int	ser_recieve_char(void)
{
	struct sigaction	sa_print;

	sa_print.sa_sigaction = ser_sighandler_receive_data;
	sa_print.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_print.sa_mask);
	sigaddset(&sa_print.sa_mask, SIGUSR1);
	sigaddset(&sa_print.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa_print, NULL);
	sigaction(SIGUSR2, &sa_print, NULL);
	while (1)
	{
		pause();
		if (g_server.printed == 1)
			break ;
	}
	return (0);
}

int	main(void)
{
	struct sigaction	sa_pre;

	ser_initialize_server();
	sa_pre.sa_sigaction = ser_sighandler_socket_ready;
	sa_pre.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_pre.sa_mask);
	sigaddset(&sa_pre.sa_mask, SIGUSR1);
	sigaddset(&sa_pre.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa_pre, NULL);
	sigaction(SIGUSR2, &sa_pre, NULL);
	while (1)
	{
		pause();
		ser_recieve_char();
	}
	return (0);
}
