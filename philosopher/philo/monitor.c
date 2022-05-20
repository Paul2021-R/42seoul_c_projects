/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:36:28 by haryu             #+#    #+#             */
/*   Updated: 2022/05/06 12:13:05 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *data)
{
	int				i;
	int				limit;
	struct timeval	*status;
	t_person		*pptr;
	struct timeval	current;

	pptr = data;
	i = 1;
	limit = pptr->public->global->num_philo;
	status = 0;
	while (1)
	{
		pthread_join(pptr->public->threads[i], (void **)&status);
		if (status)
		{
			gettimeofday(&current, NULL);
			printf("%ld %d thread is dead.\n", get_ms(current.tv_usec), i);
			break ;
		}
		usleep(100);
		if (i == limit - 1 && !status)
			i = 1;
		status = 0;
	}
	return (NULL);
}