/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:40:25 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/03 13:35:36 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_element(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'P')
	{
		(data->start_amount)++;
		data->cur_x = x;
		data->cur_y = y;
	}
	else if (data->map[y][x] == 'C')
		(data->collectible_amount)++;
	else if (data->map[y][x] == 'E')
		(data->exit_amount)++;
}

static void	check_doublons(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	ft_printf("|  Doublons check :\n");
	while (y != data->size_y)
	{
		while (x != data->size_x)
		{
			check_element(data, y, x);
			x++;
		}
		x = 0;
		y++;
	}
	doublon_error(data);
	ft_printf("|\tNo Doublons\n");
}

static void	check_ext(char *filepath)
{
	char	*ext;
	int		fd;

	ft_printf("|  Extension check :\n");
	ext = ft_strrchr(filepath, '.');
	if (!ext)
		error_exit("invalid map path");
	if (ft_strncmp(ext, ".ber", 4) != 0 && ft_strlen(ext) != 4)
		error_exit("not a .ber");
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		error_exit("file doesn't exist");
	}
	else
		close(fd);
	ft_printf("|\tGood extension\n");
}

void	ber_check(int argc, char **argv, t_data *data)
{
	ft_printf("+--- Map Checking ---\n");
	if (argc == 2)
	{
		check_ext(argv[1]);
		map_parsing(data, argv[1]);
		check_doublons(data);
		check_rectangle(data);
		check_walls(data);
		ft_printf("|  Possibility check :\n");
		if (check_is_possible(data, data->cur_y, data->cur_x) == 1)
			ft_printf("|\tMap possible\n");
		else
			error_exit("Map impossible to win");

		
	}
	else
		error_exit("invalid argument");
	ft_printf("| Successfully check map, no errors !\n+--------------------\n");
}
