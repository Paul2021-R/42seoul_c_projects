/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:05:58 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 16:09:44 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(int ac, char **av, t_common **data)
{
	(*data) = ft_malloc_wrapper(sizeof(t_common) * 1, \
"allocation is failed. : t_common");
	if (!(*data))
		return (TRUE);
	(*data)->init = ft_malloc_wrapper(sizeof(t_init) * 1, \
"allocation is failed : t_init");
	if (!(*data)->init)
		return (TRUE);
	(*data)->init->num_philo = (int)is_over_long(1, av[1], 1);
	(*data)->init->die_ms = (long)is_over_long(2, av[2], 1);
	(*data)->init->eat_ms = (long)is_over_long(2, av[3], 1);
	(*data)->init->sleep_ms = (long)is_over_long(2, av[4], 1);
	if (ac == 6)
		(*data)->init->must_eat = (long)is_over_long(5, av[5], 1);
	else
		(*data)->init->must_eat = LMAX;
	(*data)->fork_array = \
ft_malloc_wrapper(sizeof(int) * (*data)->init->num_philo, \
"allocation is failed : int array");
	if (!(*data))
		return (TRUE);
	memset((*data)->fork_array, 0, sizeof(int) * (*data)->init->num_philo);
	(*data)->death_flag = 0;
	return (FALSE);
}
