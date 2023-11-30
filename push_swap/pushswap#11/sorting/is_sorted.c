/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:34:18 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/30 10:34:19 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack_a)
{
	int	last;

	last = ft_atoi(stack_a->content);
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (last < ft_atoi(stack_a->content))
			return (0);
		last = ft_atoi(stack_a->content);
		stack_a = stack_a->next;
	}
	return (1);
}
