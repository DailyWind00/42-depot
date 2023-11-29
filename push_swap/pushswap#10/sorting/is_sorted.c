/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:01:49 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/24 14:01:23 by cjouenne         ###   ########.fr       */
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
