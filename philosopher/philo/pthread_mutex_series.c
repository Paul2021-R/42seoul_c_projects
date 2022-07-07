/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_mutex_series.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:54:22 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 19:28:34 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pthread_mutex_lock_fork(pthread_mutex_t *key, t_common	*data)
{
	int	i;

	i = 0;
	while (i < data->init->num_philo)
	{
		pthread_mutex_lock(&key[i]);
		i++;
	}
}

void	pthread_mutex_unlock_fork(pthread_mutex_t *key, t_common *data)
{
	int	i;

	i = 0;
	while (i < data->init->num_philo)
	{
		if (i % 2 == 0)
			pthread_mutex_unlock(&key[i]);
		i++;
	}
	usleep(data->init->eat_ms * 800);
	while (i >= 0)
	{
		if (i % 2 != 0)
			pthread_mutex_unlock(&key[i]);
		i--;
	}	
}
