/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 15:10:26 by haryu             #+#    #+#             */
/*   Updated: 2022/05/06 06:36:57 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(int ac, char **av, t_philo **data)
{
	(*data) = malloc (sizeof(t_philo) * 1);
	if (!(*data))
		return (1);
	(*data)->global = malloc(sizeof(t_global));
	if (!(*data)->global)
		return (1);
	(*data)->global->num_philo = (int)is_over_long(1, av[1], 1);
	(*data)->global->die_ms = (long)is_over_long(2, av[2], 1);
	(*data)->global->eat_ms = (long)is_over_long(3, av[3], 1);
	(*data)->global->sleep_ms = (long)is_over_long(4, av[4], 1);
	(*data)->global->must_eat = LMAX;
	if (ac == 6)
		(*data)->global->must_eat = is_over_long(5, av[5], 1);
	(*data)->fork = malloc(sizeof(int) * (*data)->global->num_philo);
	if (!(*data)->fork)
		return (1);
	memset((*data)->fork, 0, sizeof(int) * (*data)->global->num_philo);
	return (0);
}

t_person	*init_threads(t_philo **data)
{
	pthread_t	*threads;
	t_person	*person;

	threads = malloc (sizeof(pthread_t) * (*data)->global->num_philo);
	if (!threads)
		return (NULL);
	(*data)->threads = threads;
	person = malloc(sizeof(t_person) * (*data)->global->num_philo);
	if (!person)
		return (NULL);
	return (person);
}

int	main(int ac, char **av)
{
	t_philo			*main;
	t_person		*philosophers;

	if (check_error(ac, av))
		return (0);
	if (init_philo(ac, av, &main))
		return (0);
	philosophers = init_threads(&main);
	create_threads(philosophers, main);
	return (0);
}
