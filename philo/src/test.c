#include "philo.h"

// 먹기 => 자기 => 생각하기

// av[1] = number_of_philosophers_and_forks
// av[2] = time_to_die_in_ms
// av[3] = time_to_eat_in_ms
// av[4] = time_to_sleep_in_ms
// av[5] = number_of_times_each_philosopher_must_eat (optional)

void	print_philos(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].data->num)
	{
		printf("philos[%d].id = %d\n", i, philos[i].id);
		printf("philos[%d].right_fork = %d\n", i, philos[i].right_fork);
		printf("philos[%d].left_fork = %d\n", i, philos[i].left_fork);
		printf("philos[%d].data = %p\n", i, philos[i].data);
		i++;
	}
	printf("-------------------------------------------------\n");
	printf("number_of_philosophers                    : %d\n", philos[0].data->num);
	printf("time to die                               : %d\n", philos[0].data->t2d);
	printf("time to eat                               : %d\n", philos[0].data->t2e);
	printf("time to sleep                             : %d\n", philos[0].data->t2s);
	printf("number_of_times_each_philosopher_must_eat : %d\n", philos[0].data->must_eat);
	printf("dead flag                                 : %d\n", philos[0].data->dead);
	printf("-------------------------------------------------\n");
}

// export MallocStackLogging=1 find leaks after unset MallocStackLogging
// if you want more info about leaks use gcc -g option
// while true; do leaks minishell; sleep 1; done;
void	leak(void)
{
	system("leaks --list philo");
}
