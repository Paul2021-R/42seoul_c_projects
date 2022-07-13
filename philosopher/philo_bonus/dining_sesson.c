/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_sesson.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:47:20 by haryu             #+#    #+#             */
/*   Updated: 2022/07/13 15:04:20 by haryu            ###   ########.fr       */
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
		take_meal(man, common);
		put_down_forks(man, common);
		man->must_eat--;
		if (man->must_eat == 0)
		{
			break ;
		}
		take_sleep(man, common);
		code = try_thought(man, common);
		usleep(30);
	}
	check_death(man, common, get_ms());
	sem_wait(common->death_sem);
	sem_post(common->death_sem);
	exit(0);
}
