/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_sleep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:25:42 by haryu             #+#    #+#             */
/*   Updated: 2022/07/14 20:09:25 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_sleep(t_person *man, t_common *common)
{
	long	point;
	long	now;

	check_death(man, common, get_ms());
	usleep(200);
	printf_action(2, get_ms() - common->dining_time, \
man, common->print_sem);
	point = get_ms();
	while (TRUE)
	{
		now = get_ms() - point;
		check_death(man, common, get_ms());
		if (now >= man->sleep_ms)
			break ;
		usleep(200);
	}
	return ;
}
