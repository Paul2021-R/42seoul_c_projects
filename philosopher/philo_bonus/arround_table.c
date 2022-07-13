/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arround_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 07:06:23 by haryu             #+#    #+#             */
/*   Updated: 2022/07/13 15:25:28 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	arround_table(t_person *philosopher, t_common *common, int index)
{
	t_person	*man;

	man = &philosopher[index];
	sem_wait(common->fork_sem);
	man->prev_eat_ms = get_ms();
	common->dining_time = get_ms();
	sem_post(common->fork_sem);
	dining_session(man, common);
	exit (0);
}
