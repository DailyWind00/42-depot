/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_checking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:45:16 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/16 16:31:02 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_atoi(t_data *data, const char *str)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - 48);
	if (str[i] != 0)
		error_exit(data, "Invalid character in arguments");
	return (result);
}

void	check_arg(t_data *data, int argc, char **argv)
{
	int	x;

	x = 0;
	if (argc == 5 || argc == 6)
	{
		data->number_of_philosophers = ft_atoi(data, argv[1]);
		data->time_to_die = ft_atoi(data, argv[2]);
		data->time_to_eat = ft_atoi(data, argv[3]);
		data->time_to_sleep = ft_atoi(data, argv[4]);
		if (argc == 6)
			data->number_of_times_each_philosopher_must_eat
				= ft_atoi(data, argv[5]);
		while (x != data->number_of_philosophers)
			data->forks[x++] = true;
		data->time_eaten = 0;
	}
	else
	{
		printf("Correct syntax :\n\t./philo <number_of_philosophers> ");
		printf("<time_to_die> <time_to_eat> <time_to_sleep> ");
		printf("[number_of_times_each_philosopher_must_eat]\n");
		error_exit(data, "If confusion, check subject -> Global Rules");
	}
}
