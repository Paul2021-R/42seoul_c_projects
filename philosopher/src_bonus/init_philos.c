/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:29:43 by haryu             #+#    #+#             */
/*   Updated: 2022/07/13 15:14:47 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	put_common_to_philos(t_common **data, t_person **philos)
{
	int		i;
	t_init	*copy;

	i = -1;
	copy = (*data)->init;
	while (++i < copy->num_philo)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].die_ms = copy->die_ms;
		(*philos)[i].eat_ms = copy->eat_ms;
		(*philos)[i].sleep_ms = copy->sleep_ms;
		(*philos)[i].must_eat = copy->must_eat;
		(*philos)[i].prev_eat_ms = 0;
		(*philos)[i].public = (*data);
	}
	return ;
}

t_person	*init_philos(t_common **data)
{
	t_person	*philos;
	t_init		*init_copy;

	init_copy = (*data)->init;
	philos = ft_malloc_wrapper(sizeof(t_person) * \
init_copy->num_philo, "allocation is failed : t_person");
	if (!philos)
		return (NULL);
	put_common_to_philos(data, &philos);
	return (philos);
}
