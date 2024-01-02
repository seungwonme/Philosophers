/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:26:48 by seunan            #+#    #+#             */
/*   Updated: 2023/10/29 14:22:06 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_philo	*philo;
	t_data	data;

	if (init_data(&data, ac, av) == 1)
		return (1);
	if (init_mutex(&data) == 1)
		return (1);
	if (init_philo(&philo, &data) == 1)
	{
		free_data(&data);
		return (1);
	}
	make_thread(philo);
	free_philo(&philo);
	free_data(&data);
	return (0);
}
