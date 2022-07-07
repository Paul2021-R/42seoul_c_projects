/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_take_sleep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:18:02 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 23:09:48 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_sleep(t_person *man, int *fork)
{
	t_common	*pub;
	long		enjoy_time;

	pub = man->public;
	if (check_death(pub, man, get_ms(), fork))
		return (TRUE);
	printf_action(2, get_ms() - pub->dining_time, \
man->id, pub->print);
	while (TRUE)
	{
		enjoy_time = get_ms() - pub->dining_time;
		if (enjoy_time >= man->sleep_ms)
			break ;
		usleep(100);
	}
	return (FALSE);
}
