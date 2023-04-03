/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:59:50 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 16:10:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_person	*init_philos(t_common **data)
{
	pthread_t	*threads;
	t_person	*philos;
	int			num;

	num = (*data)->init->num_philo;
	threads = ft_malloc_wrapper(sizeof(pthread_t) * num, \
"Threads initialzing is failed.");
	if (!threads)
		return (NULL);
	(*data)->threads = threads;
	philos = ft_malloc_wrapper(sizeof(t_person) * num, \
"Pilosophers allocation is failed.");
	if (!philos)
		return (NULL);
	return (philos);
}
