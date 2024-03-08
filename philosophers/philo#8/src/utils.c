/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:56:09 by mgallais          #+#    #+#             */
/*   Updated: 2024/03/06 15:16:44 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	error_exit(t_data *data, char *strerror)
{
	if (data)
		free_data(data);
	printf("%s\n", strerror);
	exit(EXIT_FAILURE);
}

size_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_exit(NULL, "gettimeofday() FAILURE\n");
	return ((tv.tv_sec * (size_t)1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(size_t time)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < time / 1000)
		usleep(1);
}

void	philos_printf(t_philo *philo, char *str, char *color,
											bool death_message)
{
	pthread_mutex_lock(&philo->data->dying);
	if (!philo->data->someone_ded || death_message)
	{
		pthread_mutex_lock(&philo->data->writing);
		if (philo->data->someone_ded && !death_message)
		{
			pthread_mutex_unlock(philo->l_fork);
			pthread_mutex_unlock(philo->r_fork);
			pthread_mutex_unlock(&philo->data->dying);
			return ;
		}
		pthread_mutex_unlock(&philo->data->dying);
		printf("%s%zu %d %s\n%s", color, get_time() - philo->data->start_time,
			philo->id, str, RESET);
		pthread_mutex_unlock(&philo->data->writing);
		return ;
	}
	pthread_mutex_unlock(&philo->data->dying);
}
