/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:11:01 by haryu             #+#    #+#             */
/*   Updated: 2022/07/12 06:20:48 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

int	printf_action(int code, long time, t_person *man, sem_t *key)
{
	char	*str;
	char	*color;

	sem_wait(key);
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
	sem_post(key);
	return (FALSE);
}
