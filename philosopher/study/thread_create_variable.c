/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create_variable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:56:22 by haryu             #+#    #+#             */
/*   Updated: 2022/05/01 00:39:48 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// 쓰레드 함수
void	*t_function(void *data)
{
	int		id;
	int		i = 0;
	int	*ret;

	id = *((int *)data);
	while (1)
	{
		printf("Philosopher [%d] : %d\n", id, i);
		i++;
		sleep(1);
		if (i == 3)
			break ;
	}
	printf("Philosopher [%d] is turned off.\n",id);
	return ((void *)id);
}

int	main(int ac, char **av)
{
	pthread_t	*p_thread;
	int			thr_id;
	int			status;
	int			name;
	int			limit;

	limit = atoi(av[1]);
	name = 0;
	p_thread = (pthread_t *)malloc(sizeof(pthread_t) * limit);
	if (!p_thread)
	{
		perror("thread create error : ");
		exit(0);
	}
	while (name < limit)
	{
		thr_id = pthread_create(&p_thread[name], \
NULL, t_function, (void *)&name);
		if (thr_id < 0)
		{
			perror("thread create error : ");
			exit(0);
		}
		sleep(1);
		name++;
	}
	pthread_join(p_thread[limit - 1], (void **)&status);
	printf("end data : %d\n", status);
	/* 마지막의 경우를 감시하는 정도로 해도 충분하다. 무언가 죽는 경우를 확인하긴 해야 하지만, 어떤 식으로 할지 감은 온다.  */
	return (0);
}
