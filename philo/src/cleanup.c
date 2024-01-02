/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:46:49 by seunan            #+#    #+#             */
/*   Updated: 2023/10/29 14:22:26 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		++i;
	}
	pthread_mutex_destroy(&(data->print));
	pthread_mutex_destroy(&(data->lock));
	free(data->forks);
}

void	free_philo(t_philo **philo)
{
	int	i;

	i = 0;
	while (i < (*philo)->data->num)
	{
		pthread_mutex_destroy(&((*philo)->lock));
		++i;
	}
	free(*philo);
}

int	fail_init_mutex(t_data *data, int fail_idx, int flag)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(data->print));
	if (flag == 1)
		return (error(MUTEX_ERR));
	pthread_mutex_destroy(&(data->lock));
	if (flag == 2)
		return (error(MALLOC_ERR));
	while (flag == 3 && i < fail_idx - 1)
	{
		pthread_mutex_destroy(&((data->forks)[i]));
		++i;
	}
	free(data->forks);
	return (error(MUTEX_ERR));
}

int	fail_init_philo(t_philo **philo, int fail_idx)
{
	int	i;

	i = 0;
	while (i < fail_idx - 1)
	{
		pthread_mutex_destroy(&((*philo)[i].lock));
		++i;
	}
	free(*philo);
	return (error(MUTEX_ERR));
}
