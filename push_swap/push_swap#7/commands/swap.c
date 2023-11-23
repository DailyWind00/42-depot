/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:26:40 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/23 16:24:10 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sa(t_list d, bool single)
{
	if (d->size_a > 1)
	{
		swap(&(d->pile_a[0]), &(d->pile_a[1]));
		if (single)
			ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_list d, bool single)
{
	if (d->size_b > 1)
	{
		swap(&(d->pile_b[0]), &(d->pile_b[1]));
		if (single)
			ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_list d)
{
	sa(d, false);
	sb(d, false);
	ft_putstr_fd("ss\n", 1);
}
