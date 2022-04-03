/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:28:24 by haryu             #+#    #+#             */
/*   Updated: 2022/04/03 19:32:05 by haryu            ###   ########.fr       */
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


int main(int ac, char **av)
{
	struct sigaction	sa;

	cli_print_intro(ac);
	cli_connect_ready(av[1], 0, 0);
}