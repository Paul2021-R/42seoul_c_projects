/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_meal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:15:51 by haryu             #+#    #+#             */
/*   Updated: 2022/07/13 14:40:31 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_meal(t_person *man, t_common *common)
{
	long	point;
	long	now;

	check_death(man, common, get_ms());
	printf_action(1, get_ms() - common->dining_time, \
man, common->print_sem);
	point = get_ms();
	while (TRUE)
	{
		now = get_ms() - point;
		check_death(man, common, get_ms());
		if (now >= man->eat_ms)
			break ;
	}
	man->prev_eat_ms = get_ms();
	return ;
}
