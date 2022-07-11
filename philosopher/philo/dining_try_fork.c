/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_try_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:18:11 by haryu             #+#    #+#             */
/*   Updated: 2022/07/12 00:26:26 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	try_fork_another(t_person *man, int *fork)
{
	t_common	*pub;

	pub = man->public;
	if (pub->death_flag != 0 && pub->death_flag != -1)
		return (FALSE);
	if (check_death(pub, man, get_ms(), fork))
		return (FALSE);
	if (pub->fork_array[fork[1]] == 0)
	{
		pthread_mutex_lock(&pub->fork_mutex[fork[1]]);
		pub->fork_array[fork[1]] = 1;
		if (printf_action(0, get_ms() - pub->dining_time, man, pub->print))
			return (FALSE);
		return (TRUE);
	}
	else
		return (FALSE);
}

int	try_fork(t_person *man, int *fork)
{
	t_common	*pub;

	pub = man->public;
	while (TRUE)
	{
		if (pub->death_flag != 0 && pub->death_flag != -1)
			return (TRUE);
		if (check_death(pub, man, get_ms(), fork))
			return (TRUE);
		if (pub->fork_array[fork[0]] == 0)
		{
			pthread_mutex_lock(&pub->fork_mutex[fork[0]]);
			pub->fork_array[fork[0]] = 1;
			if (try_fork_another(man, fork))
				return (FALSE);
			else
			{
				pub->fork_array[fork[0]] = 0;
				pthread_mutex_unlock(&pub->fork_mutex[fork[0]]);
			}
		}
	}
}
