/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:44:03 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/21 14:00:34 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	rra(int *pile_a, int size)
{
	reverse_rotate(pile_a, size);
}

void	rrb(int *pile_b, int size)
{
	reverse_rotate(pile_b, size);
}

void	rrr(int *pile_a, int size_a, int *pile_b, int size_b)
{
	rra(pile_a, size_a);
	rrb(pile_b, size_b);
}
