/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:34:35 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/30 10:34:36 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(int *i, t_stacks_args *s_args, int j, int *k)
{
	while ((*i)--)
	{
		if (ft_lstlast(*(s_args->stack_a))->content != NULL)
		{
			if ((((ft_atoi((ft_lstlast(*(s_args->stack_a)))->content)) >> j)
					& 0x1) == 0)
			{
				pb(s_args->stack_a, s_args->stack_b);
				(*k)++;
			}
			else
				ra(s_args->stack_a, 1);
		}
	}
}
