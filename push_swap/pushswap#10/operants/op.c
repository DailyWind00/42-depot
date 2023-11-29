/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:57:26 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/21 21:53:11 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, int d)
{
	t_list	*last;
	t_list	*before_last;
	char	*tmp;

	if (d)
		ft_printf("sa\n");
	last = ft_lstlast(*stack_a);
	before_last = *stack_a;
	while (1)
	{
		if (before_last->next == last)
			break ;
		before_last = before_last->next;
	}
	tmp = ft_strdup(last->content);
	last->content = before_last->content;
	before_last->content = tmp;
}

void	sb(t_list **stack_b, int d)
{
	t_list	*last;
	t_list	*before_last;
	char	*tmp;

	if (d)
		ft_printf("sb\n");
	last = ft_lstlast(*stack_b);
	before_last = *stack_b;
	while (1)
	{
		if (before_last->next == last)
			break ;
		before_last = before_last->next;
	}
	tmp = ft_strdup(last->content);
	last->content = before_last->content;
	before_last->content = tmp;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	ft_printf("ss\n");
	sa(stack_a, 0);
	sb(stack_b, 0);
}

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
