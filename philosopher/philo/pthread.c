/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:59:41 by haryu             #+#    #+#             */
/*   Updated: 2022/05/20 10:24:12 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	around_tabe(void *data)
{
	(void)data;

	return ;
}

void	init_mutex(t_common **data)
{
	int	i;
	int	limit;

	pthread_mutex_init(&(*data)->print, NULL);
	pthread_mutex_init(&(*data)->ready, NULL);
	pthread_mutex_init(&(*data)->death, NULL);
	i = 0;
	limit = (*data)->init->num_philo;
	(*data)->m_fork = malloc(sizeof(pthread_mutex_t) * limit);
	if ((*data)->m_fork)
		return ;
	while (i < limit)
		pthread_mutex_init(&(*data)->m_fork[i++], NULL);
	return ;
}

void	init_phread(t_common **data, t_person **philos)
{
	(void)data;
	// 레디 뮤텍스
	// 쓰레드 만들기
	// 모니터 실행 
	

	return ;
}

