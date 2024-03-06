/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:40:12 by mgallais          #+#    #+#             */
/*   Updated: 2024/03/06 14:15:44 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	cooking(t_data *data, int philo_number)
{
	int		i;
	int		satisfied_philos;

	i = 0;
	satisfied_philos = 0;
	while (42)
	{
		if (satisfied_philos == philo_number)
			break ;
		pthread_mutex_lock(&data->time_eaten);
		if (data->philos[i].time_eaten == data->nb_meals)
		{
			satisfied_philos++;
			i = (i + 1) % philo_number;
		}
		pthread_mutex_unlock(&data->time_eaten);
	}
}

// This function is the routine of the cook. It makes the cook wait for all the
// philosophers to eat enough meals, then it retires and dies.
// (So someone_ded is set to true and the program ends)
void	*cuisine(void *data_struct)
{
	t_data	*data;
	int		philo_number;

	data = (t_data *)data_struct;
	pthread_mutex_lock(&data->lock);
	philo_number = data->number_of_philosophers;
	pthread_mutex_unlock(&data->lock);
	cooking(data, philo_number);
	pthread_mutex_lock(&data->dying);
	data->someone_ded = true;
	pthread_mutex_unlock(&data->dying);
	return (NULL);
}

// This function is the routine of the philosophers. It makes them eat, sleep
// and think. It also checks if someone is dead or if they eat enough meals.
void	*routine(void *philosoph)
{
	t_philo	*philo;

	philo = (t_philo *)philosoph;
	while (42)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		if (starving(philo))
			break ;
	}
	return (NULL);
}
