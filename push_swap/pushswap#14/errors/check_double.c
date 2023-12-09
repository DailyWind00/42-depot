/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:32:05 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/05 15:27:33 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
