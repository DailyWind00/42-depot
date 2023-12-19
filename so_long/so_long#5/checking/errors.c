/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:10:38 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/19 11:52:06 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_exit(char	*strerror)
{
	ft_printf("Error\n---> %s\n", strerror);
	exit(EXIT_FAILURE);
}

void	doublon_error(t_error *error)
{
	if (error->start_amount != 1)
		error_exit("must need 1 start");
	if (error->collectible_amount == 0)
		error_exit("must need atleast 1 collectible");
	if (error->exit_amount != 1)
		error_exit("must need 1 exit");
}
