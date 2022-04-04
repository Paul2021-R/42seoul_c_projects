/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:18:48 by haryu             #+#    #+#             */
/*   Updated: 2022/04/05 00:25:03 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mandatory/client.h"

t_protocol	g_client;

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

void	cli_connect_ready(char *str)
{
	int	ret;

	ret = kill(ft_atoi(str), SIGUSR1);
	if (ret)
	{
		ft_printf("Client : Your signal has a problem.\n");
		exit(1);
	}
	sigaction(SIGUSR1, &g_client.sa_pre, NULL);
	sigaction(SIGUSR2, &g_client.sa_pre, NULL);
	pause();
	return ;
}

void	ser_initialize_signal(t_protocol *data)
{
	data->received_pid = 0;
	data->printed = 0;
	data->index = 0;
	data->p = 0;
}

void	cli_sigaction_initialize(struct sigaction *sa, \
void (*f)(int, siginfo_t *, void *))
{
	sa->sa_sigaction = f;
	sa->sa_flags = SA_SIGINFO;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGUSR1);
	sigaddset(&sa->sa_mask, SIGUSR2);
	return ;
}

void	cli_send_char(char c)
{
	unsigned int	sig;

	sigaction(SIGUSR1, &g_client.sa_bit, NULL);
	sigaction(SIGUSR2, &g_client.sa_bit, NULL);
	g_client.index = 8;
	while (--g_client.index >= 0)
	{
		sig = c >> g_client.index & 1;
		ft_printf("%d", sig);
		kill(g_client.received_pid, sig + 30);
		usleep(1000);
	}
	ft_printf("    ");
	return ;
}
