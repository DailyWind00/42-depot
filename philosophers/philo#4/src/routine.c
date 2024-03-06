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

static bool	eureka(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	pthread_mutex_lock(&philo->data->dying);
	if (philo->data->someone_ded || philo->time_eaten == philo->data->nb_meals)
	{
		pthread_mutex_unlock(&philo->data->dying);
		pthread_mutex_unlock(&philo->data->lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->dying);
	pthread_mutex_unlock(&philo->data->lock);
	return (false);
}

// This function is the routine of the philosophers. It makes them eat, sleep
// and think. It also checks if someone is dead or if they eat enough meals.
void	*routine(void *philosoph)
{
	t_philo	*philo;

	philo = (t_philo *)philosoph;
	while (42)
	{
		if (eureka(philo) || starving(philo))
			break ;
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
