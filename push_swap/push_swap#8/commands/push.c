/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:34:19 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/23 16:08:07 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	pa(int *pile_a, int *size_a, int *pile_b, int *size_b)
{
	if (*(d->size_b) > 0)
	{
		d->pile_a[*(d->size_a)] = d->pile_b[*(d->size_b - 1)];
		(*(d->size_a))++;
		(*(d->size_b))--;
	}
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list d)
{
	if (*(d->size_a) > 0)
	{
		d->pile_b[*(d->size_b)] = d->pile_a[*(d->size_a) - 1];
		(*(d->size_b))++;
		(*(d->size_a))--;
	}
	ft_putstr_fd("pb\n", 1);
}
