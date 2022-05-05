/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 15:10:26 by haryu             #+#    #+#             */
/*   Updated: 2022/05/06 06:10:10 by haryu            ###   ########.fr       */
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

void	*test(void	*data)
{
	int				id;
	t_person		*pptr;
	struct timeval	*current;

	pptr = data;
	id = pptr->id;
	current = malloc(sizeof(struct timeval));
	printf("%d thread is on.\n", id);
	sleep(10);
	gettimeofday(current, NULL);
	printf("%ld %d thread is off.\n", get_ms(current->tv_usec) ,id);
	return ((void *)current);
}

void	*monitor(void *data)
{
	int				i;
	int				limit;
	struct timeval	*status;
	t_person		*pptr;
	struct timeval	current;

	pptr = data;
	i = 1;
	limit = pptr->public->global->num_philo;
	status = 0;
	while (1)
	{
		pthread_join(pptr->public->threads[i], (void **)&status);
		if (status)
		{
			gettimeofday(&current, NULL);
			printf("%ld %d thread is dead.\n", get_ms(current.tv_usec), i);
			if (i == limit - 1)
				break ;
		//	break ;
		}
		i++;
		usleep(100);
		if (i == limit - 1 && !status)
			i = 1;
		status = 0;
	}
	return (NULL);
}

void	create_threads(t_person *people, t_philo *public)
{
	int	i;
	int	limit;
	pthread_t	*thread;
	int	status;

	i = 1;
	limit = public->global->num_philo;
	thread = public->threads;
	while(i < limit)
	{
		people[i].id = i;
		people[i].must_eat = public->global->must_eat;
		people[i].sleep_ms = public->global->sleep_ms;
		people[i].die_ms = public->global->die_ms;
		people[i].eat_ms = public->global->eat_ms;
		people[i].status = SLEEPING;
		people[i].public = public;
		pthread_create(&thread[i], NULL, test, &people[i]);
		usleep(300);
		i++;
	}
	people[0].public = public;
	pthread_create(&thread[0], NULL, monitor, &people[0]);
	pthread_join(thread[0], (void **)&status);
	printf("Thread is dead so Monitor turns off.\n");
	return ;
}

int	main(int ac, char **av)
{
	t_philo			*main;
	t_person		*philosophers;

	if (check_error(ac, av))
		return (0);
	if (init_philo(ac, av, &main))
		return (0);
	//printf_main(main);
	philosophers = init_threads(&main);
	create_threads(philosophers, main);
	return (0);
}
