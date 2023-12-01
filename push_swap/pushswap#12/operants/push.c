/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:28:23 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/30 10:30:55 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*last_cpy;
	t_list	*current;

	ft_printf("pa\n");
	if (ft_lstsize(*stack_b) == 1)
	{
		current = *stack_b;
		last = *stack_b;
		last_cpy = ft_lstnew(last->content);
		ft_lstadd_back(stack_a, last_cpy);
		current->content = NULL;
		return ;
	}
	current = *stack_b;
	last = ft_lstlast(*stack_b);
	last_cpy = ft_lstnew(last->content);
	ft_lstadd_back(stack_a, last_cpy);
	while (current)
	{
		if (current->next == last)
			current->next = NULL;
		current = current->next;
	}
	free(last);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*last_cpy;
	t_list	*current;

	ft_printf("pb\n");
	if (ft_lstsize(*stack_a) == 1)
	{
		current = *stack_a;
		last = *stack_a;
		last_cpy = ft_lstnew(last->content);
		ft_lstadd_back(stack_b, last_cpy);
		current->content = NULL;
		return ;
	}
	current = *stack_a;
	last = ft_lstlast(*stack_a);
	last_cpy = ft_lstnew(last->content);
	ft_lstadd_back(stack_b, last_cpy);
	while (current)
	{
		if (current->next == last)
			current->next = NULL;
		current = current->next;
	}
	free(last);
}
