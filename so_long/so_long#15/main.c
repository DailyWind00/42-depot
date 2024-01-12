/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:02:08 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/10 10:32:02 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static void	free_data(t_data *data)
{
	int	i;

	if (data->check_map || data->map)
	{
		i = 0;
		while (i != data->size_y)
		{
			free(data->check_map[i]);
			free(data->map[i]);
			i++;
		}
		free(data->check_map);
		free(data->map);
	}
	free(data);
}

void	error_exit(t_data *data, char *strerror)
{
	free_data(data);
	ft_printf("|\tError\n+---> %s\n", strerror);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	ft_memset(data, 0, sizeof(t_data));
	ber_check(argc, argv, data);
	map_making(data);
	free_data(data);
	ft_printf("|\n| Window closed, Goodbye !\n");
	ft_printf("+--------------------\n");
	return (0);
}
