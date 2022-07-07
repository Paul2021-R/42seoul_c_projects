/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 01:26:00 by haryu             #+#    #+#             */
/*   Updated: 2022/07/07 22:19:50 by haryu            ###   ########.fr       */
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

long	get_ms(void)
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
		printf("[%d] : %d] ", i + 1, data->fork_array[i]);
		if (i + 1 < limit)
			printf("[%d] : %d] ", i + 2, data->fork_array[i + 1]);
		if (i + 2 < limit)
			printf("[%d] : %d] ", i + 3, data->fork_array[i + 2]);
		if (i + 3 < limit)
			printf("[%d] : %d] ", i + 4, data->fork_array[i + 3]);
		i += 4;
		printf("\n");
	}
}

void	printf_philos(t_common *data, t_person *philos)
{
	int	i;
	int	limit;

	i = 0;
	limit = data->init->num_philo;
	while (i < limit)
	{
		printf("=========================================\n");
		printf("1. id : %d\n", philos[i].id);
		printf("2. must_eat : %d\n", philos[i].must_eat);
		printf("3. prev_eat : %ld\n", philos[i].prev_eat_ms);
		printf("4. die limit : %ld\n", philos[i].die_ms);
		printf("5. eating time : %ld\n", philos[i].eat_ms);
		printf("6. sleep time : %ld\n", philos[i].sleep_ms);
		i++;
		if (i == limit)
			printf("=========================================\n");
	}
}

void	*ft_malloc_wrapper(size_t size, char *error)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
	{
		printf("%s%s%s\n", RED, error, WHITE);
		return (NULL);
	}
	memset(ret, 0, size);
	return (ret);
}
