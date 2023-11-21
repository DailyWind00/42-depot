/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:25:01 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/21 15:20:14 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	is_sorted(int *pile, int size)
{
	int	i;

	i = 0;
	while (i++ < size - 1)
		if (pile[i] > pile[i + 1])
			return (0);
	return (1);
}

void	push_swap(int *pile_a, int size_a)
{
	int	*pile_b;
	int	size_b;
	int	pivot;
	int	count;
	int	i;

	pile_b = malloc(size_a * sizeof(int));
	size_b = 0;
	i = 0;
	if (pile_b == NULL)
		error_exit();
	while (!is_sorted(pile_a, size_a))
	{
		if (size_a == 2)
		{
			sa(pile_a, size_a);
			ft_putstr_fd("sa\n", 1);
		}
		else if (size_a == 3)
		{
			if (pile_a[0] > pile_a[1] && pile_a[1] > pile_a[2])
			{
				sa(pile_a, size_a);
				ra(pile_a, size_a);
				ft_putstr_fd("sa\nra\n", 1);
			}
			else if (pile_a[0] > pile_a[1] && pile_a[0] > pile_a[2])
			{
				ra(pile_a, size_a);
				ft_putstr_fd("ra\n", 1);
			}
			else
			{
				sa(pile_a, size_a);
				ft_putstr_fd("sa\n", 1);
			}
		}
		else
		{
			pivot = pile_a[0];
			count = 0;
			while (i++ < size_a)
			{
				if (pile_a[i] <= pivot)
				{
					pb(pile_a, &size_a, pile_b, &size_b);
					ft_putstr_fd("pb\n", 1);
					count++;
				}
			}
			i = 0;
			while (i++ < count)
			{
				ra(pile_b, size_b);
				ft_putstr_fd("ra\n", 1);
			}
		}
	}
	free(pile_b);
}
