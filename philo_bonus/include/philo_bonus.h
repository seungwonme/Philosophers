/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:54:31 by seunan            #+#    #+#             */
/*   Updated: 2023/10/29 14:22:37 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}					t_bool;

typedef enum e_errno
{
	MALLOC_ERR = 0,
	MUTEX_ERR = 1,
	ARG_NUM_ERR = 2,
	NUM_VALUE_ERR = 3,
	T2D_VALUE_ERR = 4,
	T2E_VALUE_ERR = 5,
	T2S_VALUE_ERR = 6,
	MUST_EAT_VALUE_ERR = 7
}					t_errno;

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	lock;
	int				num;
	int				t2d;
	int				t2e;
	int				t2s;
	int				must_eat;
	char			dead;
	struct timeval	start_time;
}					t_data;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	lock;
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_cnt;
	int				is_full;
	struct timeval	last_eat;
	t_data			*data;
}					t_philo;

// init.c
int					init_data(t_data *data, int ac, char *av[]);
int					check_data(t_data *data, int ac);
int					init_mutex(t_data *data);
int					init_philo(t_philo **philo, t_data *data);
int					ft_atoi(char *str);

// routine.c
void				*philo_routine(void *arg);
int					take_two_fork(t_philo *philo);
int					eating(t_philo *philo);
int					sleeping(t_philo *philo);
int					thinking(t_philo *philo);

//monitor.c
void				make_thread(t_philo *philo);
void				monitoring(t_philo *philo);
int					check_dead(t_philo *philo, int i);
int					check_must_eat(t_philo *philo, int i, int *cnt);
void				join_philo(t_philo *philo);

// utils.c
int					spend_time(t_philo *philo, int ms);
unsigned long long	get_ms(struct timeval cur, struct timeval start);
int					is_dead(t_data *data);

// cleanup.c
void				free_data(t_data *data);
void				free_philo(t_philo **philo);
int					fail_init_mutex(t_data *data, int fail_idx, int flag);
int					fail_init_philo(t_philo **philo, int fail_idx);

// print.c
int					print_timestamp(t_philo *philo, char *s);
int					print_timestamp_eat(t_philo *philo);
void				print_success(t_philo *philo);
void				print_dead(t_philo *philo, struct timeval cur);
int					error(int flag);

#endif
