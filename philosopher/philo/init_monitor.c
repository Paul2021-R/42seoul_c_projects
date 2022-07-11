/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:01:31 by haryu             #+#    #+#             */
/*   Updated: 2022/07/12 00:13:31 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	waiting_die(t_common *common)
{
	int	i;
	int	limit;

	limit = common->init->num_philo;
	i = 0;
	while (i < limit)
	{
		pthread_join(common->threads[i], NULL);
		i++;
	}
	return ;
}

void	*monitor_thread(void *data)
{
	t_common	*common;

	common = data;
	while (TRUE)
	{
		if (common->death_flag != 0)
		{
			if (common->death_flag != -1)
			{
				usleep(20);
				pthread_mutex_lock(common->print);
				printf("%s%ld %d %s%s\n", RED, \
						get_ms() - common->dining_time, \
						common->death_flag, DEATH, WHITE);
			}
			pthread_mutex_lock(common->death);
			break ;
		}
		usleep(10);
	}
	usleep(100);
	pthread_mutex_unlock(common->death);
	pthread_mutex_unlock(common->print);
	waiting_die(common);
	return (NULL);
}

int	init_monitor(t_common *common)
{
	pthread_t	monitor;
	int			err;

	err = pthread_create(&monitor, NULL, monitor_thread, (void *)common);
	if (err < 0)
		return (return_error("monitor creation is failed.", TRUE));
	usleep(500);
	pthread_mutex_unlock_fork(common->fork_mutex, common);
	pthread_join(monitor, NULL);
	return (FALSE);
}
