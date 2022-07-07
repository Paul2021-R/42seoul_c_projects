/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:52:39 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 20:15:41 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_pthread(t_common **data, t_person **philos)
{
	int			i;
	int			limit;
	int			err;
	t_person	*temp;

	i = 0;
	limit = (*data)->init->num_philo;
	pthread_mutex_lock_fork((*data)->fork_mutex, *data);
	temp = *philos;
	while (i < limit)
	{
		err = pthread_create(&((*data)->threads[i]), NULL, \
around_table, (void *)(temp + i));
		if (err < 0)
			return (return_error("Ptrhead creation is failed.", TRUE));
		i++;
	}
	return (FALSE);
}
