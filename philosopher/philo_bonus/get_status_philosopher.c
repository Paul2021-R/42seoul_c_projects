/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_status_philosopher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 07:13:27 by haryu             #+#    #+#             */
/*   Updated: 2022/07/12 07:53:41 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	fork_release(sem_t *fork_sem, int number)
{
	int	i;

	i = 0;
	while (i < number)
	{
		sem_post(fork_sem);
		i++;
	}
	return ;
}

static void	kill_others(pid_t temp, pid_t *philosopher, int max_len)
{
	int	i;

	i = -1;
	(void)temp;
	while (++i < max_len)
	{
		printf("kill %d\n", i);
		kill(philosopher[i], SIGQUIT);
	}
	return ;
}

void	get_status_philosopher(t_person *philosopher, t_common *common)
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
		if (WIFSIGNALED(status))
			continue ;
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) != 0)
			{
				sem_wait(common->print_sem);
				printf_action(4, get_ms() - common->dining_time, &philosopher[WEXITSTATUS(status) - 1], common->fork_sem);
				kill_others(temp, common->philo_pid, max_len);
				sem_post(common->print_sem);
			}
			status = 0;
		}
	}
	return ;
}
