/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:59:41 by haryu             #+#    #+#             */
/*   Updated: 2022/05/20 21:17:00 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_think(t_person *philo)
{
	philo->status = THINKING;
	printf("%s%ld %d is thinking%s\n", \
BLUE, now_time(philo), philo->id, WHITE);
}

void	take_sleep(t_person *philo)
{
	long			inittime;

	inittime = get_ms2();
	printf("%s%ld %d is sleeping%s\n", \
PURPLE, now_time(philo), philo->id, WHITE);
	philo->status = SLEEPING;
	while (1)
	{
		if (now_time(philo) - inittime > philo->sleep_ms)
			break ;
		usleep(100);
	}
	return ;
}

void	putback_fork(t_person *philo, int fork_l, int fork_r)
{
	philo->public->fork[fork_l]--;
	philo->public->fork[fork_r]--;
	return ;
}

void	take_a_eat(t_person	*philo)
{
	long			inittime;

	inittime = now_time(philo);
	printf("%s%ld %d is eating%s\n", \
WHITE, now_time(philo), philo->id, WHITE);
	philo->status = EATING;
	while (1)
	{
		if (now_time(philo) - inittime > philo->eat_ms)
			break ;
		usleep(100);
	}
	return ;
}

void	take_fork(t_person	*philo, int fork_l, int fork_r)
{
	while (philo->status == THINKING)
	{
		if (!philo->public->fork[fork_l])
		{
			pthread_mutex_lock(&philo->public->m_fork[fork_l]);
			if(!philo->public->fork[fork_r])
				pthread_mutex_lock(&philo->public->m_fork[fork_r]);
		}
		else
		{
			pthread_mutex_unlock(&philo->public->m_fork[fork_l]);
			pthread_mutex_unlock(&philo->public->m_fork[fork_r]);
			take_think(philo);
		}
		usleep(100);
	}
	philo->public->fork[fork_l]++;
	philo->public->fork[fork_r]++;
	philo->status = READY;
	printf("%s%ld %d has taken a fork%s\n", \
GREEN, now_time(philo), philo->id, WHITE);
	take_a_eat(philo);
	putback_fork(philo, fork_l, fork_r);
	pthread_mutex_unlock(&philo->public->m_fork[fork_r]);
	pthread_mutex_unlock(&philo->public->m_fork[fork_l]);
}

void	change_fork(t_person *philo, int *fork_l, int *fork_r)
{
	int *temp;

	temp = 0;
	if (philo->id % 2 != 0)
	{
		temp = fork_l;
		fork_l = fork_r;
		fork_r = temp;
		usleep(10000);
	}
	return ;
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
	change_fork(philosopher, &fork_l, &fork_r);
	philosopher->init = get_ms2();
	pthread_mutex_unlock(&(philosopher->public->ready));
	while (1)
	{
		take_fork(philosopher, fork_l, fork_r);
		philosopher->must_eat--;
		if (philosopher->must_eat == 0)
			break ;
		take_sleep(philosopher);
		//philosopher->init = now_time(philosopher);
		usleep(500);
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
		pthread_create(&((*data)->threads[i]), NULL, around_table, (void *)(temp + i));
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
