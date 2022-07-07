/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_put_down_fork.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:18:05 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 23:09:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	put_down_forks(t_person *man, int *fork)
{
	t_common	*pub;

	pub = man->public;
	if (check_death(pub, man, get_ms(), fork))
		return (TRUE);
	pub->fork_array[fork[0]] = 0;
	pub->fork_array[fork[1]] = 0;
	pthread_mutex_unlock(&pub->fork_mutex[fork[1]]);
	pthread_mutex_unlock(&pub->fork_mutex[fork[0]]);
	return (FALSE);
}
