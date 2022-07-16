/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:24:40 by haryu             #+#    #+#             */
/*   Updated: 2022/05/02 11:44:26 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	i;
	int	k;
	int	dupli;
	int	limit;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = -1;
	dupli = 0;
	limit = ft_strlen(av[1]);
	while (++i < limit)
	{
		k = -1;
		while (av[1][++k])
		{
			if (av[1][i] == av[1][k] && k < i)
			{
				dupli = 1;
				break ;
			}
		}
		if (dupli == 0)
			write(1, &av[1][i], 1);
		else
			dupli = 0;
	}
	i = -1;
	limit = ft_strlen(av[2]);
	dupli = 0;
	while (++i < limit)
	{
		k = -1;
		while (av[1][++k])
		{
			if (av[1][k] == av[2][i])
			{
				dupli += 1;
				break ;
			}
		}
		k = -1;
		while (av[2][++k])
		{
			if (av[2][k] == av[2][i] && k < i)
			{
				dupli += 1;
				break ;
			}
		}
		if (dupli == 0)
			write(1, &av[2][i], 1);
		else
			dupli = 0;
	}
	write(1, "\n", 1);
	return (0);
}
