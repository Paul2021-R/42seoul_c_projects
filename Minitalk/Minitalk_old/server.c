/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:57:57 by haryu             #+#    #+#             */
/*   Updated: 2022/04/01 20:42:52 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_protocol	sig;



void	signal_print(char c)
{
	static char		*result;
	char			bitchar[2];

	bitchar[1] = '\0';
	bitchar[0] = c;
	result = ft_strjoin(result, bitchar);
	if (c == 0)
	{
		ft_printf("%s", result);
		free(result);
		result = 0;
	}
}

void	sending_protocol(siginfo_t *info, int code)
{
	int	ret;

	if (code == 1)
		ret = kill(info->si_pid, SIGUSR2);
	if (code == 0)
	{
		reset_signal();
		ret = kill(info->si_pid, SIGUSR1);
	}
	if (ret)
		error_print(ret);
	return ;
}

void	sighandler(int signo, siginfo_t *info, void *data)
{
	(void)data;
	kill(info->si_pid, SIGUSR1);
	signo -= SIGUSR1;
	if (sig.received_pid != info->si_pid)
		reset_signal();
	sig.p = sig.p << 1 | signo;
	sig.index++;
	if (sig.index == 8)
	{
		signal_print(sig.p);
		reset_signal();
	}
	kill(info->si_pid, SIGUSR2);
	sig.received_pid = info->si_pid;
	return ;
}

int	main(void)
{
	struct sigaction	sa;

	reset_signal();
	ft_printf("Server is activated. Server's PID : %d\n", getpid());
	sa.sa_sigaction = sighandler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
