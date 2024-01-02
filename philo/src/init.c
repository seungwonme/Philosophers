/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:21:13 by seunan            #+#    #+#             */
/*   Updated: 2023/10/29 14:22:33 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, int ac, char *av[])
{
	if (ac != 5 && ac != 6)
		return (error(ARG_NUM_ERR));
	data->forks = NULL;
	data->num = ft_atoi(av[1]);
	data->t2d = ft_atoi(av[2]);
	data->t2e = ft_atoi(av[3]);
	data->t2s = ft_atoi(av[4]);
	data->must_eat = 0;
	data->dead = 0;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	if (check_data(data, ac) == 1)
		return (1);
	return (0);
}

int	check_data(t_data *data, int ac)
{
	if (data->num < 1)
		return (error(NUM_VALUE_ERR));
	if (data->t2d < 1)
		return (error(T2D_VALUE_ERR));
	if (data->t2e < 1)
		return (error(T2E_VALUE_ERR));
	if (data->t2s < 1)
		return (error(T2S_VALUE_ERR));
	if (ac == 6 && data->must_eat < 1)
		return (error(MUST_EAT_VALUE_ERR));
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&(data->print), NULL) != 0)
		return (error(MUTEX_ERR));
	if (pthread_mutex_init(&(data->lock), NULL) != 0)
		return (fail_init_mutex(data, 0, 1));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num);
	if (!data->forks)
		return (fail_init_mutex(data, 0, 2));
	i = 0;
	while (i < data->num)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
			return (fail_init_mutex(data, i, 3));
		++i;
	}
	return (0);
}

int	init_philo(t_philo **philo, t_data *data)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * data->num);
	if (!(*philo))
		return (error(MALLOC_ERR));
	i = 0;
	while (i < data->num)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].left_fork = i;
		if (i == data->num - 1)
			(*philo)[i].right_fork = 0;
		else
			(*philo)[i].right_fork = i + 1;
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].is_full = 0;
		(*philo)[i].data = data;
		if (pthread_mutex_init(&((*philo)[i].lock), NULL) != 0)
			return (fail_init_philo(philo, i));
		++i;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			num = num * 10 + (*str - '0');
		else
			return (-1);
		if (num < 0)
			return (-1);
		str++;
	}
	return (num);
}
