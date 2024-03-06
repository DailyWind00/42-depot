/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:29:34 by mgallais          #+#    #+#             */
/*   Updated: 2024/03/06 14:41:41 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->writing);
	pthread_mutex_destroy(&data->dying);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

// This function initializes the threads and waits for them to finish.
// It also make them start the routine function.
static void	init_threads(t_data *data)
{
	int	i;

	i = 0;
	if (data->number_of_philosophers == 1)
	{
		printf("0 1  has taken a fork\n");
		usleep(data->time_to_die * 1000);
		printf("%d 1 died\n", data->time_to_die);
		return ;
	}
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
