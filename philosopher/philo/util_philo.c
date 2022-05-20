/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 01:26:00 by haryu             #+#    #+#             */
/*   Updated: 2022/05/20 21:21:59 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long	now_time(t_person *philo)
{
	struct timeval	now;
	long			now2;

	gettimeofday(&now, NULL);
	now2 = get_ms(&now);
	return (now2 - philo->init);
}

long	get_ms(struct timeval  *tiktok)
{
	long	ret;

	ret = tiktok->tv_sec * 1000 + tiktok->tv_usec / 1000;
	return (ret);
}

long	get_ms2(void)
{
	struct timeval	tiktok;
	long			ret;

	gettimeofday(&tiktok, NULL);
	ret = tiktok.tv_sec * 1000 + tiktok.tv_usec / 1000;
	return (ret);
}

void	printf_main(t_common *data)
{
	int	i;
	int	limit;

	limit = data->init->num_philo;
	printf("1. Philosopher 🧓 : %d\n", data->init->num_philo);
	printf("2. time_to_die(ms) ⏰ : %ld\n", data->init->die_ms);
	printf("3. time_to_eat(ms) ⏰ : %ld\n", data->init->eat_ms);
	printf("4. time_to_sleep(ms) ⏰ : %ld\n", data->init->sleep_ms);
	printf("5. must_eat(times) ✅ : %d\n", data->init->must_eat);
	printf("6. fork🍴 : %d\n", limit);
	i = 0;
	while (i < limit)
	{
		printf("[%d] : %d] ", i + 1, data->fork[i]);
		if (i + 1 < limit)
			printf("[%d] : %d] ", i + 2, data->fork[i + 1]);
		if (i + 2 < limit)
			printf("[%d] : %d] ", i + 3, data->fork[i + 2]);
		if (i + 3 < limit)
			printf("[%d] : %d] ", i + 4, data->fork[i + 3]);
		i += 4;
		printf("\n");
	}
}
