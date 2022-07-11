/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:23:54 by haryu             #+#    #+#             */
/*   Updated: 2022/07/12 06:47:11 by haryu            ###   ########.fr       */
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
	printf_main(common);
	philosopher = init_philos(&common);
	if (init_semaphore(&common))
		return_error("semaphore initializing is failed.", 1);
	printf_philos(common, philosopher);
	if (dinner_time(philosopher, common))
		return (TRUE);
	del_resource(&common, &philosopher);
	//atexit(ft_exit);
	return (FALSE);
}
