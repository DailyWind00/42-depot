/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:28:12 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/10 13:26:57 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* This function put the map in the terminal,               */
/* but it make valgrind errors when the map isn't rectangle */
/* (it still output an error and it's purely cosmetic)      */
void	putmap(t_data *data)
{
	int	y;

	ft_printf("|\tMap created :\n");
	y = 0;
	while (y != data->size_y)
		ft_printf("|\t\t%s\n", data->map[y++]);
}

static void	create_map(t_data *data, char *filepath)
{
	int		y;
	int		x;
	int		fd;
	char	*buf;

	y = 0;
	fd = open(filepath, O_RDONLY);
	buf = get_next_line(fd);
	while (y != data->size_y)
	{
		x = 0;
		while (buf[x] != '\n' && buf[x])
		{
			data->map[y][x] = buf[x];
			data->check_map[y][x] = '0';
			x++;
		}
		data->map[y][data->size_x] = 0;
		data->check_map[y][data->size_y] = 0;
		y++;
		free(buf);
		buf = get_next_line(fd);
	}
	close(fd);
	putmap(data);
}

static void	map_malloc(t_data *data)
{
	int	i;

	i = 0;
	data->map = malloc(sizeof(char *) * data->size_y);
	data->check_map = malloc(sizeof(char *) * data->size_y);
	while (i != data->size_y)
	{
		data->map[i] = malloc(sizeof(char) * data->size_x + 1);
		data->check_map[i++] = malloc(sizeof(char) * data->size_x + 1);
	}
}

void	map_parsing(t_data *data, char *filepath)
{
	int		fd;
	char	*buf;

	ft_printf("|  Map parsing :\n");
	fd = open(filepath, O_RDONLY);
	buf = get_next_line(fd);
	data->size_x = ft_strlen(buf) - 1;
	while (buf)
	{
		free(buf);
		(data->size_y)++;
		buf = get_next_line(fd);
	}
	if (data->size_x < 3 || data->size_y < 3)
		error_exit(data, "Invalid map");
	free(buf);
	close(fd);
	map_malloc(data);
	create_map(data, filepath);
}
