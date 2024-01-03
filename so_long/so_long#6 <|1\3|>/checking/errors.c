/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:10:38 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/03 13:06:55 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_exit(char	*strerror)
{
	ft_printf("|\tError\n+---> %s\n", strerror);
	exit(EXIT_FAILURE);
}

void	doublon_error(t_data *data)
{
	if (data->start_amount != 1)
		error_exit("must need 1 start");
	if (data->collectible_amount == 0)
		error_exit("must need atleast 1 collectible");
	if (data->exit_amount != 1)
		error_exit("must need 1 exit");
}
