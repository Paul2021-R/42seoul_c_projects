/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 02:09:19 by haryu             #+#    #+#             */
/*   Updated: 2022/05/21 02:12:48 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_ms2(void)
{
	struct timeval	tiktok;
	long			ret;

	ret = 0;
	gettimeofday(&tiktok, NULL);
	ret = tiktok.tv_sec * 1000 + tiktok.tv_usec / 1000;
	return (ret);
}

int	main(void)
{
	long	first;
	long	second;

	first = get_ms2();
	while (1)
	{
		second = get_ms2();
		if (second - first > 300)
		{
			printf("check! %ld\n", second - first);
		 	first = get_ms2();
		}
		usleep(100);
	}
}