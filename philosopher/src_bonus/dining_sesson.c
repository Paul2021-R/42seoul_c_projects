/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_sesson.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:47:20 by haryu             #+#    #+#             */
/*   Updated: 2022/07/15 01:22:12 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	dining_session(t_person *man, t_common *common)
{
	int	code;

	code = 0;
	while (TRUE && man->must_eat)
	{
		try_fork(man, common, code);
		usleep(100);
		take_meal(man, common);
		usleep(100);
		put_down_forks(man, common);
		usleep(100);
		man->must_eat--;
		if (man->must_eat == 0)
			break ;
		take_sleep(man, common);
		usleep(100);
		code = try_thought(man, common);
		usleep(100);
	}
	check_death(man, common, get_ms());
	sem_wait(common->print_sem);
	sem_wait(common->death_sem);
	sem_post(common->death_sem);
	exit(0);
}
