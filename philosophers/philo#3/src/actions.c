/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:10:52 by mgallais          #+#    #+#             */
/*   Updated: 2024/03/06 11:39:00 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	starving(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dying);
	if (philo->data->someone_ded)
	{
		pthread_mutex_unlock(&philo->data->dying);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->dying);
	pthread_mutex_lock(&philo->data->lock);
	if (get_time() - philo->last_meal > (size_t)philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->dying);
		philo->data->someone_ded = true;
		pthread_mutex_unlock(&philo->data->dying);
		pthread_mutex_unlock(&philo->data->lock);
		philos_printf(philo, "died", true);
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
	philos_printf(philo, "has taken a fork", false);
	philos_printf(philo, "has taken a fork", false);
	philos_printf(philo, "is eating", false);
	ft_usleep(philo->data->time_to_eat * 1000);
	philo->last_meal = get_time();
	philo->time_eaten++;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping(t_philo *philo)
{
	if (starving(philo))
		return ;
	philos_printf(philo, "is sleeping", false);
	ft_usleep(philo->data->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	if (starving(philo))
		return ;
	philos_printf(philo, "is thinking", false);
}