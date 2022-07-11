/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:23:54 by haryu             #+#    #+#             */
/*   Updated: 2022/07/12 00:15:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(void)
{
	system("leaks philo");
	return ;
}

int	main(int argc, char **argv)
{
	t_common	*common;
	t_person	*philos;

	if (check_error(argc, argv))
		return (TRUE);
	if (init_data(argc, argv, &common))
		return (TRUE);
	philos = init_philos(&common);
	if (!philos)
		return (TRUE);
	put_common_to_philos(&common, &philos);
	if (init_mutex(&common))
		return (TRUE);
	if (init_pthread(&common, &philos))
		return (TRUE);
	if (init_monitor(common))
		return (TRUE);
	return (FALSE);
}
