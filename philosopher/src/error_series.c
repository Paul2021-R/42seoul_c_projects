/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 01:23:14 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 14:23:37 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_error(int ac, char **av)
{
	int	i;

	if (ac != 6 && ac != 5)
	{
		printf("%sThere is input Error\n", RED);
		return (TRUE);
	}
	if (check_specific_arg(1, av[1]))
		return (TRUE);
	i = 1;
	while (++i < 5)
	{
		if (is_number(i, av[i]))
			return (TRUE);
		if (is_less_60(i, av[i]))
			return (TRUE);
		if (is_over_long(i, av[i], 0))
			return (TRUE);
	}
	if (ac == 6)
		if (check_specific_arg(5, av[5]))
			return (TRUE);
	return (FALSE);
}

int	check_specific_arg(int index, char *num)
{
	int	err;

	err = FALSE;
	if (is_number(index, num))
		return (TRUE);
	err = is_over_long(index, num, 0);
	if (err == TRUE)
		return (TRUE);
	err = is_over_long(index, num, 1);
	if (err == FALSE)
	{
		if (index == 1)
			printf("%sargv[%d]%s : Philosopher needs more than 0.\n", \
RED, index, WHITE);
		else
			printf("%sargv[%d]%s : It needs value more than 0\n", \
RED, index, WHITE);
		return (TRUE);
	}
	return (FALSE);
}

int	is_number(int index, char	*num)
{
	int	i;

	i = -1;
	while (num[++i])
	{
		if (num[i] < 48 || num[i] > 57)
		{
			printf("%sargv[%d]%s : It has wrong character.\n", \
RED, index, WHITE);
			return (TRUE);
		}		
	}
	return (FALSE);
}

int	is_less_60(int index, char *num)
{
	int			i;
	long long	value;

	value = 0;
	i = -1;
	while (num[++i])
	{
		value *= 10;
		value += num[i] - '0';
	}
	if (value <= 60)
	{
		printf("%sargv[%d]%s : It hae more than 60ms.\n", RED, index, WHITE);
		return (TRUE);
	}
	return (FALSE);
}

int	is_over_long(int index, char *num, int code)
{
	int			i;
	long long	ret;

	i = -1;
	ret = 0;
	while (num[++i])
	{
		ret *= 10;
		ret += num[i] - '0';
	}
	if (ret > LMAX)
	{
		printf("%sargv[%d]%s : It is out of range.\n", RED, index, WHITE);
		return (TRUE);
	}
	if (code == 1)
		return (ret);
	return (FALSE);
}
