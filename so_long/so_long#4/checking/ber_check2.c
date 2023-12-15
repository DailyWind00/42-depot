/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:08:03 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/15 15:12:22 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_top_bottom(char *previous_result)
{
	int	i;

	i = 0;
	while (previous_result[i + 1] != '\n')
	{
		if (previous_result[i] != '1')
		{
			free(previous_result);
			error_exit("walls aren't closed");
		}
		i++;
	}
}

void	check_walls(int fd)
{
	t_error	error;

	error.previous_result = get_next_line(fd);
	error.gnl_result = get_next_line(fd);
	error.i = ft_strlen(error.gnl_result);
	check_top_bottom(error.gnl_result);
	while (error.gnl_result)
	{
		if (error.gnl_result[0] != '1' && error.gnl_result[error.i - 1] != '1')
		{
			free(error.gnl_result);
			free(error.previous_result);
			error_exit("walls aren't closed");
		}
		error.previous_result = error.gnl_result;
		error.gnl_result = get_next_line(fd);
	}
	free(error.gnl_result);
	check_top_bottom(error.previous_result);
	free(error.previous_result);
}
