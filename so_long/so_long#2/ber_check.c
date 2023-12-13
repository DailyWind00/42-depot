/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:40:25 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/13 12:08:28 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_ext(char *filepath)
{
	int	i;

	i = 0;
	while (filepath[i] != '.' && filepath[i])
		i++;
	if (!filepath[i])
		// error exit (invalid map path)
	if (filepath[i] != ".ber")
		// error exit (not a .ber)
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
			if (error.gnl_result[error.i] == "P")
				error.start_amount++;
			else if (error.gnl_result[error.i] == "C")
				error.collectible_amount++;
			else if (error.gnl_result[error.i] == "E")
				error.exit_amount++;
		}
		error.gnl_result = get_next_line(fd);
	}
	free(error.gnl_result);
	if (error.start_amount != 1)
		// error exit (must need 1 start)
	if (error.collectible_amount == 0)
		// error exit (must need atleast 1 collectible)
	if (error.exit_amount != 1)
		// error exit (must need 1 exit)
}

static void	check_rectangle(int fd)
{
	t_error error;

	error.gnl_result = get_next_line(fd);
	error.i = 0;
	while (error.gnl_result[error.i])
		error.i++;
	error.size = error.i;
	error.i = 0;
	while (error.gnl_result)
	{
		error.gnl_result = get_next_line(fd);
		while (error.gnl_result[error.i])
			error.i++;
		if (i != error.size)
			// error exit (not a rectangle)
		error.i = 0;
	}
}

void	ber_check(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{
		check_ext(argv[1]);
		fd = fd_close_open(fd, argv[1], false);
		check_doublons(fd);
		fd = fd_close_open(fd, argv[1], true);
		check_rectangle(fd);
		fd = fd_close_open(fd, argv[1], true);
		check_walls(fd);
		fd = fd_close_open(fd, argv[1], true);
		check_possible(fd);
		close(fd);
	}
	else
		// error exit (no argument / too many argument)
	ft_printf("Successfully check map, no errors !\n");
}
