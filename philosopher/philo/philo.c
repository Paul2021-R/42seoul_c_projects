/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 00:33:01 by haryu             #+#    #+#             */
/*   Updated: 2022/05/20 09:23:58 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_common_to_philos(t_common **data, t_person **philos)
{
	int	i;
	int	limit;

	i = 0;
	limit = (*data)->init->num_philo;
	while (i < limit)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].must_eat = (*data)->init->must_eat;
		(*philos)[i].status = 0;
		(*philos)[i].die_ms = (*data)->init->die_ms;
		(*philos)[i].eat_ms = (*data)->init->eat_ms;
		(*philos)[i].sleep_ms = (*data)->init->sleep_ms;
		(*philos)[i].public = (*data);
		i++;
	}
	return ;
}

int	init_data(int ac, char **av, t_common **data)
{
	(*data) = malloc(sizeof(t_common) * 1);
	if (!(*data))
		return (TRUE);
	(*data)->init = malloc(sizeof(t_init) * 1);
	if (!(*data)->init)
		return (TRUE);
	(*data)->init->num_philo = (int)is_over_long(1, av[1], 1);
	(*data)->init->die_ms = (long)is_over_long(2, av[2], 1);
	(*data)->init->eat_ms = (long)is_over_long(2, av[3], 1);
	(*data)->init->sleep_ms = (long)is_over_long(2, av[4], 1);
	if (ac == 6)
		(*data)->init->must_eat = (long)is_over_long(5, av[5], 1);
	else
		(*data)->init->must_eat = LMAX;
	(*data)->fork = malloc(sizeof(int) * (*data)->init->num_philo);
	if (!(*data))
		return (TRUE);
	memset((*data)->fork, 0, sizeof(int) * (*data)->init->num_philo);
	(*data)->d_flag = 0;
	return (FALSE);
}

t_person	*init_philos(t_common **data)
{
	pthread_t	*threads;
	t_person	*philos;
	int			num;

	num = (*data)->init->num_philo;
	threads = malloc(sizeof(pthread_t) * num);
	if (!threads)
		return (NULL); // error 처리 해야함
	(*data)->threads = threads;
	philos = malloc(sizeof(t_person) * num);
	if (!philos)
		return (NULL); // error 처리 및 이전 것 free 해야 함
	return (philos);
}

int	main(int ac, char **av)
{
	t_common		*data;
	t_person		*philos;

	if (check_error(ac, av))
		return (FALSE);
	if (init_data(ac, av, &data))
		return (FALSE);
	printf_main(data);
	philos = init_philos(&data);
	put_common_to_philos(&data, &philos);
	init_mutex(&data);
	// init_pthread(&data);
	
	// for (int i = 0; i < data->init->num_philo; i++)
	// {
	// 	printf("check : %p\n", philos[0].public->m_fork[i]);
	// }
	return (FALSE);
}