/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 10:32:25 by mgallais          #+#    #+#             */
/*   Updated: 2023/07/23 10:33:13 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_itoal.h"

int	append_entry(char *nb, char *ref)
{
	int	fd;

	fd = open("./numbers.dict", O_WRONLY | O_APPEND);
	if (fd == -1)
		return (0);
	write(fd, "\n", 1);
	write(fd, nb, ft_strlen(nb));
	write(fd, ": ", 2);
	write(fd, ref, ft_strlen(ref));
	close(fd);
	return (1);
}
