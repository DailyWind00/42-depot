/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:10:52 by mgallais          #+#    #+#             */
/*   Updated: 2024/03/06 15:35:15 by mgallais         ###   ########.fr       */
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
		pthread_mutex_unlock(&philo->data->lock);
		pthread_mutex_lock(&philo->data->dying);
		philo->data->someone_ded = true;
		pthread_mutex_unlock(&philo->data->dying);
		philos_printf(philo, "died", B_RED, true);
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
	philos_printf(philo, "has taken a fork", B_WHITE, false);
	philos_printf(philo, "has taken a fork", B_WHITE, false);
	if (starving(philo))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	philos_printf(philo, "is eating", B_YELLOW, false);
	philo->last_meal = get_time();
	ft_usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_lock(&philo->data->time_eaten);
	philo->time_eaten++;
	pthread_mutex_unlock(&philo->data->time_eaten);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&philo->data->lock);
	i = philo->data->time_to_sleep;
	pthread_mutex_unlock(&philo->data->lock);
	if (starving(philo))
		return ;
	philos_printf(philo, "is sleeping", B_CYAN, false);
	while (i)
	{
		if (starving(philo))
			return ;
		ft_usleep(1000);
		i--;
	}
}

void	thinking(t_philo *philo)
{
	if (starving(philo))
		return ;
	philos_printf(philo, "is thinking", B_GREEN, false);
}
