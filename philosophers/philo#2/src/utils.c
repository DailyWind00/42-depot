/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:56:09 by mgallais          #+#    #+#             */
/*   Updated: 2024/03/05 12:04:42 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	get_time(void)
{
	struct timeval	tv;
	
	if (gettimeofday(&tv, NULL))
		error_exit(NULL, "gettimeofday() FAILURE\n");
	return ((tv.tv_sec * (size_t)1000) + (tv.tv_usec / 1000));
}
