/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:35:53 by haryu             #+#    #+#             */
/*   Updated: 2022/05/06 06:43:52 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*test(void	*data)
{
	int				id;
	t_person		*pptr;
	struct timeval	*current;

	pptr = data;
	id = pptr->id;
	current = malloc(sizeof(struct timeval));
	printf("%d thread is on.\n", id);
	sleep(2);
	gettimeofday(current, NULL);
	printf("%ld %d thread is off.\n", get_ms(current->tv_usec) ,id);
	return ((void *)current);
}

void	init_person(t_person *people, t_philo *public, int index)
{
	int	i;

	i = index;
	people[i].id = i;
	people[i].must_eat = public->global->must_eat;
	people[i].sleep_ms = public->global->sleep_ms;
	people[i].die_ms = public->global->die_ms;
	people[i].eat_ms = public->global->eat_ms;
	people[i].status = SLEEPING;
	people[i].public = public;
}

void	create_threads(t_person *people, t_philo *public)
{
	int			i;
	int			limit;
	pthread_t	*thread;
	int			status;

	i = 1;
	limit = public->global->num_philo;
	thread = public->threads;
	while (i < limit)
	{
		init_person(people, public, i);
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
