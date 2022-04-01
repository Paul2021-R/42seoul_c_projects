/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:58:00 by haryu             #+#    #+#             */
/*   Updated: 2022/04/01 00:43:33 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler_client(int signo)
{
	signal(SIGUSR2, sighandler_client);
	if (signo == SIGUSR1)
		pause();
	return ;
}

void	binary_print_out(char c, int pid, int code)
{
	int				i;
	int				ret;
	unsigned int	sig;

	i = 8;
	if (code == 0)
		c = 0;
	
	signal(SIGUSR1, sighandler_client);
	while (--i >= 0)
	{
		sig = c >> i & 1;
		ft_printf("%d", sig);
		ret = kill (pid, 30 + sig);
		pause();
		if (ret)
			error_print(ret);
	}
	return ;
}

int	main(int ac, char **av)
{
	int					i;
	int					j;

	print_intro(ac);
	j = 1;
	while (++j < ac)
	{
		i = 0;
		while (i < ft_strlen(av[j]))
		{
			binary_print_out(av[j][i], ft_atoi(av[1]), 1);
			ft_printf("  ");
			i++;
		}
		binary_print_out(0, ft_atoi(av[1]), 0);
	}
	return (0);
}
