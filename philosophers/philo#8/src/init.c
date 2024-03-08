/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:45:16 by mgallais          #+#    #+#             */
/*   Updated: 2024/03/06 15:35:18 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static long	ft_atoi(const char *str)
{
	size_t	i;
	long	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - 48);
	if (str[i] != 0)
		error_exit(NULL, "Invalid arguments");
	return (result);
}

// This function initializes the data structure with the arguments given to the
// program. It also initializes the mutexes.
static void	init_data(t_data *data, int number_of_philosophers, char **argv)
{
	data->number_of_philosophers = number_of_philosophers;
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nb_meals = ft_atoi(argv[5]);
	else
		data->nb_meals = -1;
	data->someone_ded = false;
	data->forks = malloc(sizeof(pthread_mutex_t) * number_of_philosophers);
	while (number_of_philosophers--)
		pthread_mutex_init(&data->forks[number_of_philosophers], NULL);
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->writing, NULL);
	pthread_mutex_init(&data->dying, NULL);
	pthread_mutex_init(&data->time_eaten, NULL);
	data->start_time = get_time();
}

// This function initializes the philos structure with the forks and the time
// they were last eaten.
static void	init_philos(t_data *data, int number_of_philosophers)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * number_of_philosophers);
	i = 0;
	while (i < number_of_philosophers)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[(i + 1) % number_of_philosophers];
		data->philos[i].time_eaten = 0;
		data->philos[i].last_meal = data->start_time;
		i++;
	}
}

void	init(t_data *data, int argc, char **argv)
{
	int	number_of_philosophers;

	if (argc == 5 || argc == 6)
	{
		number_of_philosophers = ft_atoi(argv[1]);
		init_data(data, number_of_philosophers, argv);
		init_philos(data, number_of_philosophers);
	}
	else
		error_exit(NULL, CORRECT_SYNTAX);
}
