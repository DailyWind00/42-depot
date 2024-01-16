/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:29:34 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/16 16:32:50 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	free_data(t_data *data)
{
	free(data->forks);
	free(data);
}

void	error_exit(t_data *data, char *strerror)
{
	free_data(data);
	printf("%s\n", strerror);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	memset(data, 0, sizeof(t_data));
	check_arg(data, argc, argv);
	//make thread / mutex
	//philosopher(data);
	//destroy thread / mutex
	free_data(data);
	return (0);
}
