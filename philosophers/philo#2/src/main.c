/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:29:34 by mgallais          #+#    #+#             */
/*   Updated: 2024/03/05 16:51:35 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
		pthread_mutex_destroy(&data->forks[data->number_of_philosophers]);
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->writing);
	while (data->number_of_philosophers--)
	{
		free(data->philos[i].l_fork);
		free(data->philos[i++].r_fork);
	}
	free(data->forks);
	free(data->philos);
}

void	error_exit(t_data *data, char *strerror)
{
	if (data)
		free_data(data);
	printf("%s\n", strerror);
	exit(EXIT_FAILURE);
}

// This function initializes the threads and waits for them to finish.
// It also make them start the routine function.
static void	init_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_create(&data->philos[i].thread, NULL,
				routine, &data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
		pthread_join(data->philos[i++].thread, NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init(&data, argc, argv);
	init_threads(&data);
	free_data(&data);
	return (EXIT_SUCCESS);
}
