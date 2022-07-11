/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arround_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:53:27 by haryu             #+#    #+#             */
/*   Updated: 2022/07/11 21:22:44 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	try_thought(t_common *pub, t_person *man, int *fork)
{
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

static void	*dining_session(t_person *man, int *fork)
{
	int	is_first;

	if (man->id == 1)
		is_first = 1;
	else
		is_first = 0;
	while (TRUE && man->must_eat)
	{
		if (try_fork(man, fork))
			break ;
		if (take_meal(man, fork))
			break ;
		if (put_down_forks(man, fork))
			break ;
		man->must_eat--;
		if (take_sleep(man, fork))
			break ;
		if (is_first)
			usleep(man->eat_ms);
		if (man->must_eat == 0)
			man->public->death_flag = -1;
		try_thought(man->public, man, fork);
	}
	pthread_mutex_lock(man->public->death);
	if (man->public->death_flag == man->id)
		printf_action(4, get_ms() - man->public->dining_time, \
man, man->public->print);
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
