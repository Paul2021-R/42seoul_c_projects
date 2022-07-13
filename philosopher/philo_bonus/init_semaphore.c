/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 02:43:59 by haryu             #+#    #+#             */
/*   Updated: 2022/07/13 15:15:00 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	sem_open_wrapper(int code, sem_t **ptr, size_t size)
{
	char	*str;

	if (code == 1)
		str = "fork_sem";
	else if (code == 2)
		str = "death_sem";
	else
		str = "print_sem";
	(*ptr) = sem_open(str, O_CREAT | O_EXCL, 0644, size);
	if ((*ptr) == SEM_FAILED)
	{
		printf("error is here\n");
		sem_unlink(str);
		sem_open_wrapper(code, ptr, size);
	}
	return ;
}

int	init_semaphore(t_common **data)
{
	sem_open_wrapper(1, &(*data)->fork_sem, (*data)->init->num_philo);
	sem_open_wrapper(2, &(*data)->death_sem, 1);
	sem_open_wrapper(3, &(*data)->print_sem, 1);
	return (FALSE);
}
