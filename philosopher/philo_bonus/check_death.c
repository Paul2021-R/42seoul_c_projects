/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:56:01 by haryu             #+#    #+#             */
/*   Updated: 2022/07/13 15:09:29 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_death(t_person *man, t_common *common, long now)
{
	long	interval;

	interval = now - man->prev_eat_ms;
	if (interval < man->die_ms)
		return ;
	else
	{
		sem_post(common->fork_sem);
		sem_post(common->fork_sem);
		printf_action(4, now - common->dining_time, man, common->print_sem);
		exit(man->id);
	}
}
