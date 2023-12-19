/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:40:25 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/19 12:06:52 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_ext(char *filepath)
{
	char	*ext;

	ext = ft_strrchr(filepath, '.');
	if (!ext)
		error_exit("invalid map path");
	if (ft_strncmp(ext, ".ber", 4) != 0)
		error_exit("not a .ber");
	ft_printf("Good extension\n");
}

static void	check_doublons_element(t_data *data, t_error *error, int x, int y)
{
	if (error->gnl_result[error->i] == 'P')
	{
		error->start_amount++;
		data->start_x = x;
		data->start_y = y;
	}
	else if (error->gnl_result[error->i] == 'C')
		error->collectible_amount++;
	else if (error->gnl_result[error->i] == 'E')
		error->exit_amount++;
}

static void	check_doublons(t_data *data, t_error *error, int fd)
{
	error->gnl_result = get_next_line(fd);
	free(error->previous_result);
	error->i = 0;
	data->index = 0;
	error->start_amount = 0;
	error->collectible_amount = 0;
	error->exit_amount = 0;
	while (error->gnl_result)
	{
		free(error->previous_result);
		while (error->gnl_result[error->i])
		{
			check_doublons_element(data, error, error->i, data->index);
			(error->i)++;
		}
		(data->index)++;
		error->gnl_result = get_next_line(fd);
	}
	free(error->previous_result);
	doublon_error(error);
	ft_printf("No doublons\n");
}

static void	check_rectangle(t_data *data, t_error *error, int fd)
{
	error->gnl_result = get_next_line(fd);
	error->i = 0;
	error->size = ft_strlen(error->gnl_result - 1);
	data->size_x = ft_strlen(error->gnl_result - 1);
	data->size_y = 0;
	while (error->gnl_result)
	{
		error->gnl_result = get_next_line(fd);
		while (error->gnl_result[error->i]
			&& error->gnl_result[error->i] != '\n')
			error->i++;
		if (error->i != error->size)
			error_exit("not a rectangle");
		(data->size_y)++;
		error->i = 0;
	}
}

void	ber_check(int argc, char **argv, t_data *data)
{
	t_error	*error;
	int		fd;

	error = NULL;
	if (argc == 2)
	{
		check_ext(argv[1]);
		fd = fd_close_open(fd, argv[1], false);
		check_doublons(data, error, fd);
		fd = fd_close_open(fd, argv[1], true);
		check_rectangle(data, error, fd);
		fd = fd_close_open(fd, argv[1], true);
		check_walls(fd);
		fd = fd_close_open(fd, argv[1], true);
		map_parsing(data, error, fd);
		check_is_possible(data, error, data->start_y, data->start_x);
	}
	else
		error_exit("invalid argument");
	ft_printf("Successfully check map, no errors !\n");
}
