/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:33:21 by haryu             #+#    #+#             */
/*   Updated: 2022/04/01 20:40:38 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_protocol g_client;

int	cli_connect_ready(char *str, int code, pid_t serverpid)
{
	struct sigaction	sa_pre;
	int					ret;

	initialize_signal(&g_client, 0);
	sa_pre.sa_sigaction = cli_sighandler_pre;
	sa_pre.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_pre.sa_mask);
	sigaddset(&sa_pre.sa_mask, SIGUSR1);
	sigaddset(&sa_pre.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa_pre, NULL);
	sigaction(SIGUSR2, &sa_pre, NULL);
	if (code == 0)
		ret = kill(ft_atoi(str), SIGUSR2);
	else
		ret = kill(serverpid, SIGUSR2);
	if (ret)
		cli_error_print(ret);
	pause();
	return (0);
}

void	cli_sighandler_pre(int signo, siginfo_t *info, void *data)
{
	(void)data;
	if (signo == SIGUSR2)
	{
		ft_printf("Clinet : Server is connected.\n");
		g_client.received_pid = info->si_pid;
	}
	else if (signo == SIGUSR1)
	{
		while (1)
		{
			ft_printf("Client : Server is busy. Should be waiting.\n");
			sleep(3);
			if (!cli_connect_ready(NULL, 1, info->si_pid))
				break ;
		}
	}
	return ;
}

void	cli_sighandler_print(int signo, siginfo_t *info, void *data)
{
	struct sigaction	sa_printafter;

	sa_printafter.sa_sigaction = cli_sighandler_print;
	sa_printafter.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_printafter.sa_mask);
	sigaddset(&sa_printafter.sa_mask, SIGUSR2);
	sigaddset(&sa_printafter.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &sa_printafter, NULL);
	sigaction(SIGUSR2, &sa_printafter, NULL);
	(void)data;
	if (signo == SIGUSR2)
		ft_printf("Clinet : Print a next sentence.\n");
	else if (signo == SIGUSR1)
	{
		ft_printf("Client : Server is busy. Should be waiting.\n");
		sleep(3);
		kill(info->si_pid, SIGUSR2);
		pause();
	}
	return ;
}

void	cli_sighandler_char(int signo)
{
	if (signo == SIGUSR1)
	{
		ft_printf("Client : Server make a request stop.\n");
		exit(0);
	}
	return ;
}

void	cli_send_char_to_binary(char c)
{
	int				i;
	int				ret;
	unsigned int	sig;

	i = 8;
	signal(SIGUSR2, cli_sighandler_char);
	signal(SIGUSR1, cli_sighandler_char);
	while (--i >= 0)
	{
		sig = c >> i & 1;
		ft_printf("%d", sig);
		usleep(1000);
		ret = kill (g_client.received_pid, 30 + sig);
		pause();
		if (ret)
			cli_error_print(ret);
	}
	ft_printf("  ");
	return ;
}

void	cli_send_message(char *str)
{
	while (*str)
	{	
		cli_send_char_to_binary(*str);
		str++;
	}
	cli_send_char_to_binary('\0');
	return ;
}

int	main(int ac, char **av)
{
	struct sigaction	sa_printafter;
	int					i;

	cli_print_intro(ac);
	cli_connect_ready(av[1], 0, 0);
	sa_printafter.sa_sigaction = cli_sighandler_print;
	sa_printafter.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_printafter.sa_mask);
	sigaddset(&sa_printafter.sa_mask, SIGUSR2);
	sigaddset(&sa_printafter.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &sa_printafter, NULL);
	sigaction(SIGUSR2, &sa_printafter, NULL);
	i = 2;
	while (i < ac)
	{
		cli_send_message(av[i]);
		i++;
		if (i == ac)
			break ;
		pause();
	}
	return (0);
}
