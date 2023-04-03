/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:40:52 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 16:48:44 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_common **data)
{
	int	i;
	int	limit;

	(*data)->print = ft_malloc_wrapper(sizeof(pthread_mutex_t) * 1, \
"Allocation is failed : mutex_lock");
	if (!(*data)->print)
		return (TRUE);
	pthread_mutex_init((*data)->print, NULL);
	(*data)->death = ft_malloc_wrapper(sizeof(pthread_mutex_t) * 1, \
"Allocation is failed : mutex_lock");
	if (!(*data)->death)
		return (TRUE);
	pthread_mutex_init((*data)->death, NULL);
	i = 0;
	limit = (*data)->init->num_philo;
	(*data)->fork_mutex = malloc(sizeof(pthread_mutex_t) * limit);
	if (!(*data)->fork_mutex)
		return (TRUE);
	while (i < limit)
		pthread_mutex_init(&(*data)->fork_mutex[i++], NULL);
	return (FALSE);
}
