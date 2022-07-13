/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_down_forks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:22:03 by haryu             #+#    #+#             */
/*   Updated: 2022/07/13 14:25:00 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	put_down_forks(t_person *man, t_common *common)
{
	check_death(man, common, get_ms());
	sem_post(common->fork_sem);
	sem_post(common->fork_sem);
	return ;
}
