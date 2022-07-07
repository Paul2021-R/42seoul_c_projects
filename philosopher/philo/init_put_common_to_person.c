/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_put_common_to_person.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:17:01 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 23:41:28 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_common_to_philos(t_common **data, t_person **philos)
{
	int	i;
	int	limit;

	i = 0;
	limit = (*data)->init->num_philo;
	while (i < limit)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].must_eat = (*data)->init->must_eat;
		(*philos)[i].die_ms = (*data)->init->die_ms;
		(*philos)[i].eat_ms = (*data)->init->eat_ms;
		(*philos)[i].sleep_ms = (*data)->init->sleep_ms;
		(*philos)[i].public = (*data);
		(*philos)[i].prev_eat_ms = 0;
		i++;
	}
	return ;
}