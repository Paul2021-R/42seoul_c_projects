/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:23:54 by haryu             #+#    #+#             */
/*   Updated: 2022/07/15 01:12:40 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_exit(void)
{
	system("leaks philo_bonus");
	return ;
}

int	main(int argc, char **argv)
{
	t_common	*common;
	t_person	*philosopher;

	if (check_error(argc, argv))
		return (TRUE);
	if (init_data(argc, argv, &common))
		return (TRUE);
	philosopher = init_philos(&common);
	if (init_semaphore(&common))
		return_error("semaphore initializing is failed.", 1);
	if (dinner_time(philosopher, common))
		return (TRUE);
	del_resource(&common, &philosopher);
	//return (FALSE);
	ft_exit();
}
