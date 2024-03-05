/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:10:52 by mgallais          #+#    #+#             */
/*   Updated: 2024/03/05 16:57:41 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	starving(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->someone_ded)
	{
		pthread_mutex_unlock(&philo->data->lock);
		return (true);
	}
	else if (get_time() - philo->last_meal > (size_t)philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->writing);
		printf("%zu %d died\n", get_time() - philo->data->start_time,
			philo->id);
		pthread_mutex_unlock(&philo->data->writing);
		philo->data->someone_ded = true;
		pthread_mutex_unlock(&philo->data->lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->lock);
	return (false);
}

void	eating(t_philo *philo)
{
	if (starving(philo))
		return ;
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(&philo->data->writing);
	printf("%zu %d is eating\n", get_time() - philo->data->start_time,
		philo->id);
	pthread_mutex_unlock(&philo->data->writing);
	usleep(philo->data->time_to_eat * 1000);
	philo->time_eaten++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping(t_philo *philo)
{
	if (starving(philo))
		return ;
	pthread_mutex_lock(&philo->data->writing);
	printf("%zu %d is sleeping\n", get_time() - philo->data->start_time,
		philo->id);
	pthread_mutex_unlock(&philo->data->writing);
	usleep(philo->data->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	if (starving(philo))
		return ;
	pthread_mutex_lock(&philo->data->writing);
	printf("%zu %d is thinking\n", get_time() - philo->data->start_time,
		philo->id);
	pthread_mutex_unlock(&philo->data->writing);
}