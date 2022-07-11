/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arround_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 07:06:23 by haryu             #+#    #+#             */
/*   Updated: 2022/07/12 07:58:15 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	arround_table(t_person *philosopher, t_common *common, int index)
{
	sem_wait(common->fork_sem);
	printf("%d is ready : %d\n", philosopher[index].id, index);
	printf("%lu\n", get_ms() - common->dining_time);
	sleep(3);
	sem_post(common->fork_sem);
	if (philosopher[index].id == 2)
	{
		sem_wait(common->print_sem);
		printf("%d : I am die here : 1\n", philosopher[index].id);
		sem_post(common->print_sem);
		exit (philosopher[index].id);
	}
	else
	{
		sleep(1);
		sem_wait(common->print_sem);
		printf("%d : I am die here : 0\n", philosopher[index].id);
		sem_post(common->print_sem);
		exit (0);
	}
}
