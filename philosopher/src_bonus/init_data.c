/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:05:58 by haryu             #+#    #+#             */
/*   Updated: 2022/07/12 06:40:33 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_data(int ac, char **av, t_common **data)
{
	(*data) = ft_malloc_wrapper(sizeof(t_common) * 1, \
"allocation is failed. : t_common");
	(*data)->init = ft_malloc_wrapper(sizeof(t_init) * 1, \
"allocation is failed : t_init");
	if (!(*data) || !(*data)->init)
		return (TRUE);
	(*data)->init->num_philo = (int)is_over_long(1, av[1], 1);
	(*data)->init->die_ms = (long)is_over_long(2, av[2], 1);
	(*data)->init->eat_ms = (long)is_over_long(2, av[3], 1);
	(*data)->init->sleep_ms = (long)is_over_long(2, av[4], 1);
	if (ac == 6)
		(*data)->init->must_eat = (long)is_over_long(5, av[5], 1);
	else
		(*data)->init->must_eat = LMAX;
	(*data)->philo_pid = ft_malloc_wrapper(sizeof(pid_t) * \
			(*data)->init->num_philo, \
			"allocation is failed. : pid_t");
	(*data)->fork_sem = ft_malloc_wrapper(sizeof(sem_t), \
			"allocation is failed. : sem_t fork");
	(*data)->print_sem = ft_malloc_wrapper(sizeof(sem_t) * 1, \
			"allocation is failed. : sem_t print");
	(*data)->death_sem = ft_malloc_wrapper(sizeof(sem_t) * 1, \
			"allocation is failed. : sem_t death");
	return (FALSE);
}
