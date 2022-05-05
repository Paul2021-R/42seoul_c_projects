/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 15:05:30 by haryu             #+#    #+#             */
/*   Updated: 2022/05/06 04:26:25 by haryu            ###   ########.fr       */
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

/* global data */
typedef struct s_global
{
	int		num_philo;
	int		must_eat;
	long	die_ms;
	long	eat_ms;
	long	sleep_ms;
}				t_global;

/* main data */
typedef struct s_philo
{
	t_global		*global;
	int				*fork;
	pthread_t		*threads;
	pthread_mutex_t	ready;
	pthread_mutex_t	mutex;
	pthread_mutex_t	last;
}				t_philo;

/* Status of Philosopher */
typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING
}				t_status;

/* specific philo */
typedef struct s_person
{
	int				id;
	int				must_eat;
	t_status		status;
	long			die_ms;
	long			eat_ms;
	long			sleep_ms;
	t_philo			*public;
}				t_person;
/*
 * id : 0 = monitor, id : 1 ~ num_philo = Real number of philosophers.
 */

/* functs, 'action_target' */
/* error handller */
int		check_error(int ac, char **av);
int		is_number(int index, char *num);
int		is_less_60(int index, char *num);
int		is_over_long(int index, char *num, int code);
int		check_specific_arg(int index, char *num);
/* Initialize main data */
int		init_philo(int ac, char **av, t_philo **data);

/* utils */
int		ft_strlen(char *s);
void	printf_main(t_philo *data);
long	get_ms(long current);
#endif
