/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_thought.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:32:08 by haryu             #+#    #+#             */
/*   Updated: 2022/07/13 14:41:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	try_thought(t_person *man, t_common *common)
{
	check_death(man, common, get_ms());
	printf_action(3, get_ms() - common->dining_time, \
man, common->print_sem);
	sem_wait(common->fork_sem);
	sem_wait(common->fork_sem);
	check_death(man, common, get_ms());
	return (1);
}
