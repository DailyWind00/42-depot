/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:57:14 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/24 16:06:50 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pushswap.h"

void	ft_free(t_list d)
{
	if (d->pile_a)
		free(d->pile_a);
	if (d->size_a)
		free(d->size_a);
	if (d->pile_b)
		free(d->pile_b);
	if (d->size_b)
		free(d->size_b);
	if (d)
		free(d);
}
