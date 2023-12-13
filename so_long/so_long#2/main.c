/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:02:08 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/13 11:59:24 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// true = close & open | false = open only
int	fd_close_open(int fd, char *filepath, bool close)
{
	if (close)
		close(fd);
	fd = open(filepath, O_RDONLY, 0);
	if (fd < 0)
		// error exit (invalid read)
	return (fd);
}

int	main(int argc, const char **argv)
{
	ber_check(argc, argv);
	return (0);
}
