/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_resource.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 06:31:30 by haryu             #+#    #+#             */
/*   Updated: 2022/07/14 19:33:29 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	free_t_common(t_common **common)
{
	sem_unlink("fork_sem");
	sem_unlink("death_sem");
	sem_unlink("print_sem");
	sem_close((*common)->fork_sem);
	sem_close((*common)->death_sem);
	sem_close((*common)->print_sem);
	free((*common)->philo_pid);
	free((*common)->init);
	free((*common));
}

void	del_resource(t_common **common, t_person **philosopher)
{
	free((*philosopher));
	free_t_common(common);
}
