/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:17:58 by seunan            #+#    #+#             */
/*   Updated: 2023/10/28 15:48:58 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = philo->data->start_time;
	if (philo->id % 2 == 0)
		spend_time(philo, philo->data->t2e);
	while (TRUE)
	{
		if (take_two_fork(philo) == 1)
			return (NULL);
		if (eating(philo) == 1)
			return (NULL);
		if (sleeping(philo) == 1)
			return (NULL);
		if (thinking(philo) == 1)
			return (NULL);
	}
	return (NULL);
}

int	take_two_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
	if (print_timestamp(philo, "has taken a fork") == 1)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		return (1);
	}
	if (philo->data->num == 1)
	{
		usleep(philo->data->t2d);
		return (1);
	}
	pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
	if (print_timestamp(philo, "has taken a fork") == 1)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		return (1);
	}
	return (0);
}

int	eating(t_philo *philo)
{
	if (print_timestamp_eat(philo) == 1)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		return (1);
	}
	if (spend_time(philo, philo->data->t2e) == 1)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		return (1);
	}
	pthread_mutex_lock(&philo->lock);
	++(philo->eat_cnt);
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (print_timestamp(philo, "is sleeping") == 1)
		return (1);
	if (spend_time(philo, philo->data->t2s) == 1)
		return (1);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (print_timestamp(philo, "is thinking") == 1)
		return (1);
	return (0);
}
