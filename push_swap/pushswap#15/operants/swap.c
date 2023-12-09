/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:27:57 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/09 15:05:27 by mgallais         ###   ########.fr       */
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
	tmp = last->content;
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
	tmp = last->content;
	last->content = before_last->content;
	before_last->content = tmp;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	ft_printf("ss\n");
	sa(stack_a, 0);
	sb(stack_b, 0);
}
