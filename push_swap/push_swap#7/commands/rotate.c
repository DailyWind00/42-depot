/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:37:07 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/23 16:15:37 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

static void	rotate(int *pile, int size)
{
	int	temp;
	int	i;

	i = 0;
	if (size > 1)
	{
		temp = pile[0];
		while (i++ < size - 1)
			pile[i] = pile[i + 1];
		pile[size - 1] = temp;
	}
}

void	ra(t_list d, bool single)
{
	rotate(d->pile_a, d->size_a);
	if (single)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_list d, bool single)
{
	rotate(d->pile_b, d->size_b);
	if (single)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_list d)
{
	ra(d, false);
	rb(d, false);
	ft_putchar_fd("rr\n", 1);
}
