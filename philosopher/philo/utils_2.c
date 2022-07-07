/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:11:01 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 20:42:15 by haryu            ###   ########.fr       */
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
		return (DEATH);
}

int	printf_action(int code, long time, int target, pthread_mutex_t *key)
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
	printf("%s%ld %d %s%s\n", color, time, target, WHITE);
	pthread_mutex_unlock(key);
}
