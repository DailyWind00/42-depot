/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:28:12 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/08 16:33:54 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	create_map(t_data *data, char *filepath)
{
	int		y;
	int		x;
	int		fd;
	char	*buf;

	y = 0;
	fd = open(filepath, O_RDONLY);
	while (y != data->size_y)
	{
		buf = get_next_line(fd);
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
	}
	close(fd);
	ft_printf("|\tMap created\n");
	y = 0;
	while (y != data->size_y)
		ft_printf("|\t\t%s\n", data->map[y++]);
}

void	map_parsing(t_data *data, char *filepath)
{
	int		i;
	int		fd;
	char	*buf;

	i = 0;
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
	free(buf);
	close(fd);
	data->map = malloc(sizeof(char *) * data->size_y);
	data->check_map = malloc(sizeof(char *) * data->size_y);
	while (i != data->size_y)
	{
		data->map[i] = malloc(sizeof(char) * data->size_x + 1);
		data->check_map[i++] = malloc(sizeof(char) * data->size_x + 1);
	}
	create_map(data, filepath);
}
