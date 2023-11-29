/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:34:02 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/24 13:59:59 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error(t_list **stack_a)
{
	free_stack(stack_a);
	ft_printf("Error\n");
	exit(0);
}

void	check_double(t_list **stack_a)
{
	t_list	*i;
	t_list	*j;
	t_list	*current;

	current = *stack_a;
	i = *stack_a;
	while (i)
	{
		j = current;
		while (j)
		{
			if (j == i)
			{
				j = j->next;
				continue ;
			}
			if (ft_atoi(i->content) == ft_atoi(j->content))
				error(stack_a);
			j = j->next;
		}
		i = i->next;
	}
}
