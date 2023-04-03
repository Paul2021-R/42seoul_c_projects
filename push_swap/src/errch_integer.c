/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errch_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:23:53 by haryu             #+#    #+#             */
/*   Updated: 2022/04/24 19:03:15 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include <stdio.h>

void	put_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	error_no_integer(int i, char *str)
{
	int	error;

	error = 0;
	if (i == 0)
		if (str[0] != '0')
			error = 1;
	if (i == -1)
		if (str[0] != '-')
			error = 1;
	if (error == 1)
		put_error();
	else
		return ;
}

void	error_no_duplicates(int *arr, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = i + 1;
		while (j < len)
			if (arr[i] == arr[j++])
				put_error();
	}
	return ;
}

void	int_over_error_check(char *str)
{
	long long	ret;
	int			i;
	int			minus;

	ret = 0;
	i = 0;
	minus = 1;
	if (str[i] == '-')
	{
		i = 1;
		minus = -1;
	}
	while (str[i])
	{
		ret *= 10;
		ret += (str[i] - '0');
		if ((str[i] - '0') > 9)
			put_error();
		i++;
	}
	ret *= minus;
	if (ret < -2147483648 || ret > 2147483647)
		put_error();
	else
		return ;
}

int	*error_check(int limit, char **array)
{
	int	*ret;
	int	i;

	i = 0;
	ret = malloc(sizeof(int) * limit);
	while (i < limit - 1)
	{
		ret[i] = ft_atoi(array[i + 1]);
		int_over_error_check(array[i + 1]);
		error_no_integer(ret[i], array[i + 1]);
		i++;
	}
	error_no_duplicates(ret, limit - 1);
	return (ret);
}
