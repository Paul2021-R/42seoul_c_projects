/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:28:24 by haryu             #+#    #+#             */
/*   Updated: 2022/04/05 00:27:38 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/client_bonus.h"

t_protocol	g_client;

void	cli_sighandler_pre(int signo, siginfo_t *info, void *data)
{
	(void)data;
	(void)signo;
	if (info->si_signo == SIGUSR1)
	{
		ft_printf("Client : Server is connected.\n\
Client : Server PID is [ %d ]\n", info->si_pid);
		g_client.received_pid = info->si_pid;
		return ;
	}
	else
	{
		ft_printf("Client : Server connection is failed.\n");
		exit(0);
	}
}

void	cli_sighandler_char(int signo, siginfo_t *info, void *data)
{
	(void)signo;
	(void)data;
	if (info->si_signo == SIGUSR1)
		ft_printf("Client : Server is ready to receive data.\n");
	else
	{
		ft_printf("Client : Server send that work is finished.\n");
		ft_printf("Client : Sending message is perfectly finished.\n");
		exit(0);
	}
	return ;
}

void	cli_sighandler_bit(int signo, siginfo_t *info, void *data)
{
	(void)data;
	(void)info;
	if (signo == SIGUSR1)
		return ;
	else
	{
		ft_printf("\nClient : Sending data is finished.\n");
	}
	exit(0);
}

void	cli_send_message(char *str)
{
	usleep(5000);
	kill(g_client.received_pid, SIGUSR1);
	sigaction(SIGUSR1, &g_client.sa_char, NULL);
	sigaction(SIGUSR2, &g_client.sa_char, NULL);
	pause();
	while (*str)
	{
		cli_send_char(*str);
		str++;
	}
	cli_send_char('\0');
	pause();
}

int	main(int ac, char **av)
{
	cli_print_intro(ac);
	cli_sigaction_initialize(&g_client.sa_pre, &cli_sighandler_pre);
	cli_sigaction_initialize(&g_client.sa_char, &cli_sighandler_char);
	cli_sigaction_initialize(&g_client.sa_bit, &cli_sighandler_bit);
	cli_connect_ready(av[1]);
	cli_send_message(av[2]);
	return (0);
}
