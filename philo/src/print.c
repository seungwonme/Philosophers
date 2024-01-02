/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:22:07 by seunan            #+#    #+#             */
/*   Updated: 2023/10/29 14:10:52 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_timestamp(t_philo *philo, char *s)
{
	struct timeval	cur;

	pthread_mutex_lock(&philo->data->print);
	if (is_dead(philo->data))
	{
		pthread_mutex_unlock(&(philo->data->print));
		return (1);
	}
	gettimeofday(&cur, NULL);
	printf("%llu %d %s\n", get_ms(cur, philo->data->start_time),
		philo->id, s);
	pthread_mutex_unlock(&philo->data->print);
	return (0);
}

int	print_timestamp_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->print));
	if (is_dead(philo->data))
	{
		pthread_mutex_unlock(&(philo->data->print));
		return (1);
	}
	pthread_mutex_lock(&philo->lock);
	gettimeofday(&(philo->last_eat), NULL);
	pthread_mutex_unlock(&philo->lock);
	printf("%llu %d is eating\n", get_ms(philo->last_eat,
			philo->data->start_time), philo->id);
	pthread_mutex_unlock(&philo->data->print);
	return (0);
}

void	print_success(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->print));
	printf("\033[32m");
	printf("All philos ate %d times\n", philo->data->must_eat);
	printf("\033[0m");
	pthread_mutex_unlock(&(philo->data->print));
}

void	print_dead(t_philo *philo, struct timeval cur)
{
	pthread_mutex_lock(&(philo->data->print));
	printf("\033[33m");
	printf("%llu %d died\n", get_ms(cur, philo->data->start_time),
		philo->id);
	printf("\033[0m");
	pthread_mutex_unlock(&(philo->data->print));
}

int	error(int flag)
{
	printf("\033[31m");
	if (flag == MALLOC_ERR)
		printf("Error: Failed malloc");
	if (flag == MUTEX_ERR)
		printf("Error: Failed mutex initialization");
	if (flag == ARG_NUM_ERR)
		printf("Usage: ./philo num t2d t2e t2s [must_eat]");
	if (flag == NUM_VALUE_ERR)
		printf("Error: Invalid value number of philosophers");
	if (flag == T2D_VALUE_ERR)
		printf("Error: Invalid value time to die");
	if (flag == T2E_VALUE_ERR)
		printf("Error: Invalid value time to eat");
	if (flag == T2S_VALUE_ERR)
		printf("Error: Invalid value time to sleep");
	if (flag == MUST_EAT_VALUE_ERR)
		printf("Error: Invalid value number of times each philo must eat");
	printf("\n\033[0m");
	return (1);
}
