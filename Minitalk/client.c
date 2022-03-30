/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:58:00 by haryu             #+#    #+#             */
/*   Updated: 2022/03/31 01:11:50 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	binary_print_out(char c, int pid, int code)
{
	int	i;
	unsigned int	signal;

	i = 8;
	if (code == 0)
		c = 0;
	while (--i >= 0)
	{
		signal = c >> i & 1;
		if (signal == 1)
		{	
			ft_printf("1");
			kill (pid, SIGUSR1);
		}
		else
		{
			ft_printf("0");
			kill (pid, SIGUSR2);
		}
		usleep(600);
	}
	return ;
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 2)
	{
		ft_printf("사용법: ./a.out [프로세스 ID] [문장들] ... \n");
	}
	j = 1;
	while (++j < ac)
	{
		i = 0;
		while (i < ft_strlen(av[j]))
		{
			binary_print_out(av[j][i], ft_atoi(av[1]), 1);
			usleep(1000);
			ft_printf("  ");
			i++;
		}
		binary_print_out(0, ft_atoi(av[1]), 0);
		usleep(1000);
	}
	return (0);
}