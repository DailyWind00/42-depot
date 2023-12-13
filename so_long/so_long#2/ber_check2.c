/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:08:03 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/13 12:28:07 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	check_top_bottom(char *previous_result)
{
	int	i;

	i = 0;
	while (previous_result[i + 1] != "\n")
	{
		if (previous_result[i] != "1")
			// error exit (walls aren't close)
		error.i++;
	}
}

void	check_walls(int fd)
{
	t_error	error;

	error.previous_result = get_next_line(fd);
	error.gnl_result = get_next_line(fd);
	error.i = ft_strlen(error.gnl_result);
	while (error.gnl_result)
	{
		if (error.gnl_result[0] != "1" && error.gnl_result[i - 1] != "1")
			// error exit (walls aren't close)
		error.previous_result = error.gnl_result;
		error.gnl_result = get_next_line(fd);
	}
	free(error.gnl_result);
	check_top_bottom(error.previous_result);
	free(error.previous_result);
}

