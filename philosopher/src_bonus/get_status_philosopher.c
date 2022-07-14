/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_status_philosopher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 07:13:27 by haryu             #+#    #+#             */
/*   Updated: 2022/07/14 17:51:14 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	fork_release(sem_t *fork_sem, int number)
{
	int	i;

	i = -1;
	while (++i < number)
		sem_post(fork_sem);
	return ;
}

static void	kill_others(pid_t temp, pid_t *philosopher, int max_len)
{
	int	i;

	i = -1;
	while (++i < max_len)
	{
		if (temp == philosopher[i])
			continue ;
		kill(philosopher[i], SIGINT);
	}
	return ;
}

static int	check_status(int status, t_common *common, pid_t temp)
{
	if (WIFSIGNALED(status))
		return (0);
	if (status)
	{
		if (WEXITSTATUS(status) != 0)
		{
			kill_others(temp, common->philo_pid, common->init->num_philo);
			usleep(400);
			sem_post(common->death_sem);
		}
	}
	return (0);
}

void	get_status_philosopher(t_common *common)
{
	int		i;
	int		max_len;
	int		status;
	pid_t	temp;

	max_len = common->init->num_philo;
	i = -1;
	common->dining_time = get_ms();
	fork_release(common->fork_sem, max_len);
	while (++i < max_len)
	{
		temp = waitpid(-1, &status, 0);
		sem_wait(common->print_sem);
		sem_wait(common->death_sem);
		status = check_status(status, common, temp);
		sem_post(common->print_sem);
	}
	return ;
}
