/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:59:41 by haryu             #+#    #+#             */
/*   Updated: 2022/05/21 02:21:25 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_think(t_person *philo)
{
	return ;
}

void	take_sleep(t_person *philo)
{
	return ;
}

void	putback_fork(t_person **philo, int fork_l, int fork_r)
{
	return ;
}

void	take_a_eat(t_person	*philo)
{
	return ;
}

void	take_fork(t_person	*philo, int fork_l, int fork_r)
{
	return ;
}

int	change_fork(t_person *philo, int *fork_l, int *fork_r)
{
	int	*temp;

	temp = 0;
	if (philo->id % 2 != 0)
	{
		temp = fork_l;
		fork_l = fork_r;
		fork_r = temp;
		return (0);
	}
	return (1);
}

void	*around_table(void *data)
{
	t_person		*philosopher;
	int				index;
	int				fork_l;
	int				fork_r;

	philosopher = data;
	index = philosopher->id - 1;
	pthread_mutex_lock(&(philosopher->public->ready));
	philosopher->init = now_time(philosopher);
	fork_l = (index + philosopher->public->init->num_philo) % \
	philosopher->public->init->num_philo;
	fork_r = (index + 1) % philosopher->public->init->num_philo;
	philosopher->status = THINKING;
	philosopher->init = get_ms2();
	pthread_mutex_unlock(&(philosopher->public->ready));
	if(!change_fork(philosopher, &fork_l, &fork_r))
		take_sleep(philosopher);
	while (1)
	{
		take_fork(philosopher, fork_l, fork_r);
		philosopher->must_eat--;
		if (philosopher->must_eat == 0)
			break ;
		take_sleep(philosopher);
		take_think(philosopher);
	}
	return (NULL);
}

void	init_mutex(t_common **data)
{
	int	i;
	int	limit;

	pthread_mutex_init(&(*data)->print, NULL);
	pthread_mutex_init(&(*data)->ready, NULL);
	pthread_mutex_init(&(*data)->death, NULL);
	i = 0;
	limit = (*data)->init->num_philo;
	(*data)->m_fork = malloc(sizeof(pthread_mutex_t) * limit);
	if ((*data)->m_fork)
		return ;
	while (i < limit)
		pthread_mutex_init(&(*data)->m_fork[i++], NULL);
	return ;
}

void	init_pthread(t_common **data, t_person **philos)
{
	int			i;
	int			limit;
	t_person	*temp;

	i = 0;
	limit = (*data)->init->num_philo;
	pthread_mutex_lock(&(*data)->ready);
	temp = *philos;
	while (i < limit)
	{

		pthread_create(&((*data)->threads[i]), \
NULL, around_table, (void *)(temp + i));
		i++;
	}
	// 모니터 실행 
	pthread_mutex_unlock(&(*data)->ready);
	i = 0;
	while (i < limit)
	{
		pthread_join((*data)->threads[i], NULL);
		i++;
	}
	return ;
}
