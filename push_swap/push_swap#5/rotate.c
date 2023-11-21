/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:37:07 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/21 13:59:40 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	ra(int *pile_a, int size)
{
	rotate(pile_a, size);
}

void	rb(int *pile_b, int size)
{
	rotate(pile_b, size);
}

void	rr(int *pile_a, int size_a, int *pile_b, int size_b)
{
	ra(pile_a, size_a);
	rb(pile_b, size_b);
}
