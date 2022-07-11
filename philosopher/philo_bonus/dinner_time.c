/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 06:22:09 by haryu             #+#    #+#             */
/*   Updated: 2022/07/12 07:28:01 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	fork_hold(sem_t *fork_sem, int number)
{
	int	i;

	i = 0;
	while (i < number)
	{
		sem_wait(fork_sem);
		i++;
	}
	return ;
}

static void	philosopher_seat(t_person *philosopher, t_common *common)
{
	int	i;

	i = 0;
	while (i < common->init->num_philo)
	{
		common->philo_pid[i] = fork();
		if (common->philo_pid[i] == 0)
			arround_table(philosopher, common, i);
		else
			i++;
	}
}

int	dinner_time(t_person *philosopher, t_common *common)
{
	fork_hold(common->fork_sem, common->init->num_philo);
	philosopher_seat(philosopher, common);
	get_status_philosopher(philosopher, common);
	return (0);
}
