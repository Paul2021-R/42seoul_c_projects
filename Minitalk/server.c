/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:57:57 by haryu             #+#    #+#             */
/*   Updated: 2022/03/31 01:21:19 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	sighandler1(int signo)
{
	static int		i;
	static char		ret_bit;

	if (signo == SIGUSR1)
	{
		if (i == 0)
			ret_bit = 1;
		ret_bit = ret_bit << 1;
		ret_bit = ret_bit | 1;
	}
	else if (signo == SIGUSR2)
	{
		if (i == 0)
			ret_bit = 0;
		ret_bit = ret_bit << 1;
	}
	i++;
	if (i == 8)
	{
		i = 0;
		signal_print(ret_bit);
		ret_bit = 0;
	}
	return ;
}

int	main(void)
{
	pid_t	mypid;
	int		i;

	mypid = getpid();
	ft_printf("Server is activated. Server's PID : %d\n", mypid);
	while (1)
	{
		signal(SIGUSR1, sighandler1);
		signal(SIGUSR2, sighandler1);
		usleep(100);
	}
	return (0);
}