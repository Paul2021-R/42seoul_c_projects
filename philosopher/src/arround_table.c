/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arround_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:53:27 by haryu             #+#    #+#             */
/*   Updated: 2022/07/15 00:58:12 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	try_thought(t_common *pub, t_person *man, int *fork)
{
	if (pub->death_flag != 0 && pub->death_flag != -1)
		return (TRUE);
	if (check_death(pub, man, get_ms(), fork))
		return (TRUE);
	if (printf_action(3, get_ms() - pub->dining_time, man, pub->print))
		return (TRUE);
	while (TRUE)
	{
		if (pub->fork_array[fork[0]] == 0 && (get_ms() - \
man->prev_eat_ms) * 2 > man->die_ms)
			break ;
		usleep(10);
	}
	return (FALSE);
}

static void	eat_count(t_person *man)
{
	pthread_mutex_lock(man->public->death);
	man->public->eat_flag++;
	man->must_eat = -1;
	pthread_mutex_unlock(man->public->death);
}

static void	*dining_session(t_person *man, int *fork)
{
	while (TRUE && man->must_eat)
	{
		if (try_fork(man, fork))
			break ;
		if (take_meal(man, fork))
			break ;
		if (put_down_forks(man, fork))
			break ;
		if (man->must_eat != -1)
			man->must_eat--;
		if (take_sleep(man, fork))
			break ;
		if (man->must_eat == 0)
			eat_count(man);
		if (try_thought(man->public, man, fork))
			break ;
	}
	check_death(man->public, man, get_ms(), fork);
	pthread_mutex_lock(man->public->death);
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
	pthread_mutex_lock(&(man->public->fork_mutex[fork[0]]));
	pthread_mutex_unlock(&(man->public->fork_mutex[fork[0]]));
	man->prev_eat_ms = get_ms();
	change_fork(id, fork);
	dining_session(man, fork);
	return (NULL);
}
