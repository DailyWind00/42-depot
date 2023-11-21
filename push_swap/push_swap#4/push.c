/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:34:19 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/21 13:36:45 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(int *pile_a, int *size_a, int *pile_b, int *size_b)
{
	if (*size_b > 0)
	{
		pile_a[*size_a] = pile_b[*size_b - 1];
		(*size_a)++;
		(*size_b)--;
	}
}

void	pb(int *pile_a, int *size_a, int *pile_b, int *size_b)
{
	if (*size_a > 0)
	{
		pile_b[*size_b] = pile_a[*size_a - 1];
		(*size_b)++;
		(*size_a)--;
	}
}
