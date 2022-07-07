/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arround_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:53:27 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 23:16:38 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*dining_session(t_person *man, int *fork)
{
	while (TRUE)
	{
		if (try_fork(man, fork))
			break ;
		if (take_meal(man, fork))
			break ;
		if (put_down_forks(man, fork))
			break ;
		man->must_eat--;
		if (man->must_eat == 0)
			return (NULL);
		if (take_sleep(man, fork))
			break ;
		usleep(100);
	}
	pthread_mutex_lock(man->public->death);
	// printf_action(4, get_ms() - man->public->dining_time, \
// man->id, man->public->print);
	pthread_mutex_unlock(man->public->death);
	return (NULL);
}

static void	change_fork(int id, int *fork)
{
	int	temp;

	if (id % 2 != 0)
	{
		temp = fork[0];
		fork[0] = fork[1];
		fork[1] = temp;
	}
	return ;
}

void	*around_table(void *data)
{
	t_person	*man;
	int			id;
	int			fork[2];

	man = data;
	id = man->id;
	fork[0] = (man->id - 1 + man->public->init->num_philo) % \
man->public->init->num_philo;
	fork[1] = (man->id + man->public->init->num_philo) % \
man->public->init->num_philo;
	pthread_mutex_lock(&(man->public->fork_mutex[id]));
	change_fork(id, fork);
	man->prev_eat_ms = get_ms();
	pthread_mutex_unlock(&(man->public->fork_mutex[id]));
	return (dining_session(man, fork));
}
