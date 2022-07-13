/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:04:07 by haryu             #+#    #+#             */
/*   Updated: 2022/07/13 14:31:40 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	try_fork(t_person *man, t_common *common, int code)
{
	while (TRUE)
	{
		check_death(man, common, get_ms());
		if (code == 0)
		{
			sem_wait(common->fork_sem);
			sem_wait(common->fork_sem);
		}
		printf_action(0, get_ms() - common->dining_time, \
man, common->print_sem);
		check_death(man, common, get_ms());
		break ;
	}
}
