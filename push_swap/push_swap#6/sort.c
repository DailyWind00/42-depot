/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:25:01 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/23 14:01:54 by mgallais         ###   ########.fr       */
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

static int find_pivot(int *pile, int size)
{
	int first;
	int middle;
	int last;

	first = pile[0];
	middle = pile[size / 2];
	last = pile[size - 1];
	if ((first <= middle && middle <= last) || (last <= middle && middle <= first))
		return (middle);
	else if ((middle <= first && first <= last) || (last <= first && first <= middle))
		return (first);
	else
		return (last);
}

void	push_swap(int *pile_a, int size_a)
{
	int	*pile_b;
	int	size_b;
	int	pivot;
	int	count;
	int prev_size_a;

	prev_size_a = size_a;
	pile_b = malloc(size_a * sizeof(int));
	size_b = 0;
	if (!pile_b)
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
			pivot = find_pivot(pile_a, size_a);
			count = 0;
			while (size_a > 0 && pile_a[0] > pivot)
			{
				pb(pile_a, &size_a, pile_b, &size_b);
				ft_putstr_fd("pb\n", 1);
				count++;
			}
			while (count-- > 0)
			{
				ra(pile_b, size_b);
				ft_putstr_fd("ra\n", 1);
			}
			ra(pile_a, size_a);
			ft_putstr_fd("ra\n", 1);
		}ize_a == 2)
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
			pivot = find_pivot(pile_a, size_a);
			count = 0;
			while (size_a > 0 && pile_a[0] > pivot)
			{
				pb(pile_a, &size_a, pile_b, &size_b);
				ft_putstr_fd("pb\n", 1);
				count++;
			}
			while (count-- > 0)
			{
				ra(pile_b, size_b);
				ft_putstr_fd("ra\n", 1);
			}
			ra(pile_a, size_a);
			ft_putstr_fd("ra\n", 1);
		}
		if (prev_size_a == size_a)
			break;
		prev_size_a = size_a;
	}
	free(pile_b);
}

		if (prev_size_a == size_a)
			break;
		prev_size_a = size_a;
	}
	free(pile_b);
}

/*
**	todo :
**		-new sorting
*/
