/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:11:01 by haryu             #+#    #+#             */
/*   Updated: 2022/07/11 23:37:18 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	return_error(char *error, int value)
{
	printf("%s%s%s\n", RED, error, WHITE);
	return (value);
}

static char	*which_color(int code)
{
	if (code == 0)
		return (BLUE);
	else if (code == 1)
		return (GREEN);
	else if (code == 2)
		return (PURPLE);
	else if (code == 3)
		return (CYAN);
	else
		return (RED);
}

int	printf_action(int code, long time, t_person *man, pthread_mutex_t *key)
{
	char	*str;
	char	*color;

	pthread_mutex_lock(key);
	color = which_color(code);
	if (code == 0)
		str = FORK;
	else if (code == 1)
		str = MEAL;
	else if (code == 2)
		str = SLEEP;
	else if (code == 3)
		str = THOUGHT;
	else
		str = DEATH;
	printf("%s%ld %d %s%s\n", color, time, man->id, str, WHITE);
	pthread_mutex_unlock(key);
	return (FALSE);
}

int	check_death(t_common *pub, t_person *man, long now, int *fork)
{
	long	interval;

	if (pub->death_flag != 0 && pub->death_flag != -1)
	{
		pub->fork_array[fork[0]] = 0;
		pub->fork_array[fork[1]] = 0;
		pthread_mutex_unlock(&pub->fork_mutex[fork[1]]);
		pthread_mutex_unlock(&pub->fork_mutex[fork[0]]);
		return (TRUE);
	}
	interval = now - man->prev_eat_ms;
	if (interval < man->die_ms)
		return (FALSE);
	else
	{
		if (pub->death_flag == -1)
		{
			if (man->must_eat != 0)
				return (TRUE);
			else
				return (FALSE);
		}
		pub->death_flag = man->id;
		return (TRUE);
	}
}
