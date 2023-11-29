/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:52:52 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/21 21:46:06 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, int d)
{
	t_list	*last;
	t_list	*last_cpy;
	t_list	*current;

	if (d)
		ft_printf("ra\n");
	if (ft_lstsize(*stack_a) <= 1)
		return ;
	current = *stack_a;
	last = ft_lstlast(*stack_a);
	last_cpy = ft_lstnew(last->content);
	ft_lstadd_front(stack_a, last_cpy);
	while (current)
	{
		if (current == current->next)
			return ;
		if (current->next == last)
			current->next = NULL;
		current = current->next;
	}
	free(last);
}

void	rb(t_list **stack_b, int d)
{
	t_list	*last;
	t_list	*last_cpy;
	t_list	*current;

	if (d)
		ft_printf("rb\n");
	if (ft_lstsize(*stack_b) <= 1)
		return ;
	current = *stack_b;
	last = ft_lstlast(*stack_b);
	last_cpy = ft_lstnew(last->content);
	ft_lstadd_front(stack_b, last_cpy);
	while (current)
	{
		if (current->next == last)
			current->next = NULL;
		current = current->next;
	}
	free(last);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_printf("rr\n");
}

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
