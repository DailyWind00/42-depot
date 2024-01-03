/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:02:08 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/03 10:51:15 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
	ber_check(argc, argv, data);
	// ...
	free(data);
	return (0);
}