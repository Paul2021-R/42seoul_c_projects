/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 01:26:00 by haryu             #+#    #+#             */
/*   Updated: 2022/05/06 04:19:59 by haryu            ###   ########.fr       */
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

long	get_ms(long current)
{
	long	ret;

	ret = current / 1000;
	return (ret);
}

void	printf_main(t_philo *data)
{
	int	i;
	int	limit;

	limit = data->global->num_philo;
	printf("1. Philosopher 🧓 : %d\n", data->global->num_philo);
	printf("2. time_to_die(ms) ⏰ : %ld\n", data->global->die_ms);
	printf("3. time_to_eat(ms) ⏰ : %ld\n", data->global->eat_ms);
	printf("4. time_to_sleep(ms) ⏰ : %ld\n", data->global->sleep_ms);
	printf("5. must_eat(times) ✅ : %d\n", data->global->must_eat);
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
