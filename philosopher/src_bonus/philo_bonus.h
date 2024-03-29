/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 15:05:30 by haryu             #+#    #+#             */
/*   Updated: 2022/07/13 15:34:31 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

/* requiremet header */
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
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
	long			dining_time;
	pid_t			*philo_pid;
	sem_t			*fork_sem;
	sem_t			*death_sem;
	sem_t			*print_sem;
}				t_common;

/**
 * @brief philosophers data
 * @id index of philosophers
 * @must_eat the maximum number of meals
 * @status status of philosophers
 * @prev_eat_ms	For evaluating die or not.
 * @public data of initialization and mutexes
 */

typedef struct s_person
{
	int				id;
	int				must_eat;
	long			die_ms;
	long			eat_ms;
	long			sleep_ms;
	long			prev_eat_ms;
	t_common		*public;
}				t_person;

/* Utils */

int			ft_strlen(char *s);
/**
 * @brief get millisec now.
 * 
 */
long		get_ms(void);
/**
 * @brief print common datas.
 * 
 */
void		printf_main(t_common *data);
/**
 * @brief malloc wrapper. malloc and error handler. 
 * If it is succed, you can get variable initialized zero.
 * 
 * @param size size of allocation
 * @param error what error handling strings
 * @return void* pointer of allocated var.
 */
void		*ft_malloc_wrapper(size_t size, char *error);
/**
 * @brief print whole philosopher(initialized)
 * 
 * @param data 
 * @param philos 
 */
void		printf_philos(t_common *data, t_person *philos);
int			return_error(char *error, int value);
int			printf_action(int code, long time, \
t_person *man, sem_t *key);

/* error */

/**
 * @brief error check
 * 
 * @param ac 
 * @param av 
 * @return int True or False 
 */
int			check_error(int ac, char **av);
int			check_specific_arg(int index, char *num);
int			is_number(int index, char	*num);
int			is_less_60(int index, char *num);
int			is_over_long(int index, char *num, int code);
int			init_mutex(t_common **data);

/* Initialize tools */

int			init_data(int ac, char **av, t_common **data);
t_person	*init_philos(t_common **data);
int			init_semaphore(t_common **data);
int			dinner_time(t_person *philosopher, t_common *data);
void		del_resource(t_common **common, t_person **philosopher);

/* dining philosopher */
void		arround_table(t_person *philosopher, t_common *common, int index);
void		dining_session(t_person *man, t_common *common);
void		get_status_philosopher(t_common *common);
void		check_death(t_person *man, t_common *common, long now);
void		try_fork(t_person *man, t_common *common, int code);
void		take_meal(t_person *man, t_common *common);
void		put_down_forks(t_person *man, t_common *common);
void		take_sleep(t_person *man, t_common *common);
int			try_thought(t_person *man, t_common *common);

#endif
