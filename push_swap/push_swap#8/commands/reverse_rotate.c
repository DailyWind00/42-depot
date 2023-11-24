/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:44:03 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/23 16:13:36 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

static void	reverse_rotate(int *pile, int size)
{
	int	temp;
	int	i;

	i = size - 1;
	if (size > 1)
	{
		temp = pile[size - 1];
		while (i > 0)
			pile[i] = pile[i - 1];
		pile[0] = temp;
	}
}

void	rra(t_list d, bool single)
{
	reverse_rotate(d->pile_a, d->size_a);
	if (single)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list d, bool single)
{
	reverse_rotate(d->pile_b, d->size);
	if (single)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list d)
{
	rra(d, false);
	rrb(d, false);
	ft_putstr_fd("rrr\n", 1);
}
