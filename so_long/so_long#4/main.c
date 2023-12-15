/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:02:08 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/15 13:43:17 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

// true = close & open | false = open only
int	fd_close_open(int fd, char *filepath, bool do_close)
{
	if (do_close)
		close(fd);
	fd = open(filepath, O_RDONLY, 0);
	if (fd < 0)
		error_exit("invalid read");
	return (fd);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	ber_check(argc, argv, data);
	// ...
	return (0);
}