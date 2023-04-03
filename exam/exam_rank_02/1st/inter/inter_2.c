/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:08:47 by haryu             #+#    #+#             */
/*   Updated: 2022/05/02 11:22:04 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

int main(int ac, char **av)
{
	int	i;
	int	j;
	int k;
	int limit;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = -1;
	limit = ft_strlen(av[1]);
	while (++i < limit)
	{
		k = -1;
		while(av[1][++k])
		{
			if (av[1][k] == av[1][i] && i > k)
			{
				i++;
				break ;
			}
		}
		j = -1;
		while (av[2][++j])
		{
			if (av[1][i] == av[2][j])
			{
				write (1, &av[1][i], 1);
				break ;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}