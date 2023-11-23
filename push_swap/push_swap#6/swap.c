/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:26:40 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/21 13:34:06 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sa(int *pile, int size)
{
	if (size > 1)
		swap(&pile[0], &pile[1]);
}

void	sb(int *pile, int size)
{
	if (size > 1)
		swap(&pile[0], &pile[1]);
}

void	ss(int *pile_a, int size_a, int *pile_b, int size_b)
{
	sa(pile_a, size_a);
	sb(pile_b, size_b);
}
