/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 15:05:30 by haryu             #+#    #+#             */
/*   Updated: 2022/05/20 02:02:08 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* requiremet header */
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include <unistd.h>
# include <sys/time.h>

# define LMAX 2147483647
# define LMIN (-2147483648)
# define TRUE 1
# define FALSE 0
# define FORK "has taken a fork"
# define MEAL "is eating"
# define SLEEP "is sleeping"
# define THOUGHT "is thinking"
# define DEATH "died"

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

/**
 * @brief variables for initializing
 * 
 */
typedef struct s_init
{
	int		num_philo;
	int		must_eat;
	long	die_ms;
	long	eat_ms;
	long	sleep_ms;
}				t_init;

/**
 * @brief Variables for common datas
 * 
 */
typedef struct s_common
{
	t_init			*init;
	int				*fork;
	int				d_flag;
	pthread_t		*threads;
	pthread_mutex_t	ready;
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
}				t_common;

/**
 * @brief status datas
 * 
 */
typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING
}				t_status;

/**
 * @brief philosophers data
 * @id index of philosophers
 * @must_eat the maximum number of meals
 * @status status of philosophers
 * @public data of initialization and mutexes
 */
typedef struct s_person
{
	int				id;
	int				must_eat;
	t_status		status;
	long			die_ms;
	long			eat_ms;
	long			sleep_ms;
	t_common		*public;
}				t_person;

/* functs, 'action_target' */
/* error handller */
/**
 * @brief Check errors about under casess
 * (1) not numbers, (2) minimum values, (3) over values
 * @param ac 
 * @param av 
 * @return True or False
 */
int		check_error(int ac, char **av);
int		is_number(int index, char *num);
int		is_less_60(int index, char *num);
int		is_over_long(int index, char *num, int code);
int		check_specific_arg(int index, char *num);

void	init_phread(t_common **data);
void	init_mutex(t_common **data);

/* utils */
int		ft_strlen(char *s);
long	get_ms(long current);
void	printf_main(t_common *data);
#endif
