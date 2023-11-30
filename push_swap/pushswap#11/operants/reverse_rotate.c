/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:29:29 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/30 10:30:44 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a, int d)
{
	t_list	*first;
	t_list	*first_cpy;

	if (d)
		ft_printf("rra\n");
	first = *stack_a;
	first_cpy = ft_lstnew(first->content);
	ft_lstadd_back(stack_a, first_cpy);
	(*stack_a) = (*stack_a)->next;
	free(first);
}

void	rrb(t_list **stack_b, int d)
{
	t_list	*first;
	t_list	*first_cpy;

	if (d)
		ft_printf("rrb\n");
	first = *stack_b;
	first_cpy = ft_lstnew(first->content);
	ft_lstadd_back(stack_b, first_cpy);
	(*stack_b) = (*stack_b)->next;
	free(first);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	ft_printf("rrr\n");
	rra(stack_a, 0);
	rrb(stack_b, 0);
}
