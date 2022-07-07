/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_take_sleep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:18:02 by haryu             #+#    #+#             */
/*   Updated: 2022/07/08 00:35:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_sleep(t_person *man, int *fork)
{
	t_common	*pub;
	long		enjoy_time;
	long		point;

	pub = man->public;
	if (check_death(pub, man, get_ms(), fork))
		return (TRUE);
	if (printf_action(2, get_ms() - pub->dining_time, \
man, pub->print))
		return (TRUE);
	point = get_ms();
	while (TRUE)
	{
		enjoy_time = get_ms() - point;
		if (enjoy_time >= man->sleep_ms)
			break ;
	}
	return (FALSE);
}
