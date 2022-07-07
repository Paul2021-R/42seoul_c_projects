/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arround_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:53:27 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 21:14:43 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*dining_session(t_person *man, int *fork)
{
	while (TRUE)
	{
		try_fork(fork, man);
		if (take_meal(fork, man))
			printf_action(4, man->prev_eat_ms - get_ms(), \
man->id, man->public->death);
		man->prev_eat_ms = get_ms();
		put_down_fork(fork, man);
		man->must_eat--;
		if (man->must_eat == 0)
			return (NULL);
		take_sleep(man);
	}
	return (NULL);
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
	man->status = THINKING;
	pthread_mutex_lock(&(man->public->fork_mutex[id]));
	man->prev_eat_ms = man->public->dining_time;
	pthread_mutex_unlock(&(man->public->fork_mutex[id]));
	return (dining_session(man, fork));
}
