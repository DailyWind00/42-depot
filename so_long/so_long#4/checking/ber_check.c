/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:40:25 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/15 15:13:05 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_ext(char *filepath)
{
	int		i;
	char	*ext;

	ext = ft_strrchr(filepath, '.');
	if (!ext)
		error_exit("invalid map path");
	if (ft_strncmp(&filepath[i], ".ber", 4) != 0)
		error_exit("not a .ber");
}

static void	check_doublons(int fd)
{
	t_error	error;

	error.gnl_result = get_next_line(fd);
	error.i = 0;
	error.start_amount = 0;
	error.collectible_amount = 0;
	error.exit_amount = 0;
	while (error.gnl_result)
	{
		while (error.gnl_result[error.i])
		{
			if (error.gnl_result[error.i] == 'P')
				error.start_amount++;
			else if (error.gnl_result[error.i] == 'C')
				error.collectible_amount++;
			else if (error.gnl_result[error.i] == 'E')
				error.exit_amount++;
		}
		error.gnl_result = get_next_line(fd);
	}
	free(error.gnl_result);
	doublon_error(error);
}

static void	check_rectangle(t_data *data, int fd)
{
	t_error	error;

	error.gnl_result = get_next_line(fd);
	error.i = 0;
	error.size = ft_strlen(error.gnl_result - 1);
	data->size_x = ft_strlen(error.gnl_result - 1);
	data->size_y = 0;
	while (error.gnl_result)
	{
		error.gnl_result = get_next_line(fd);
		while (error.gnl_result[error.i] && error.gnl_result[error.i] != '\n')
			error.i++;
		if (error.i != error.size)
			error_exit("not a rectangle");
		(data->size_y)++;
		error.i = 0;
	}
	free(error.gnl_result);
}

void	ber_check(int argc, char **argv, t_data *data)
{
	int	fd;

	if (argc == 2)
	{
		check_ext(argv[1]);
		fd = fd_close_open(fd, argv[1], false);
		check_doublons(fd);
		fd = fd_close_open(fd, argv[1], true);
		check_rectangle(data, fd);
		fd = fd_close_open(fd, argv[1], true);
		check_walls(fd);
		fd = fd_close_open(fd, argv[1], true);
		map_parsing(data, fd);
		check_possible(data);
	}
	else
	{
		if (argc < 2)
			error_exit("no argument");
		else
			error_exit("too many argument");
	}
	ft_printf("Successfully check map, no errors !\n");
}
