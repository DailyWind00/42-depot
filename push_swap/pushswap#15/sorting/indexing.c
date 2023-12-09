/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:34:08 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/09 11:59:13 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	index_stack2(t_index_var **iv, t_list **stack_a)
{
	while ((*iv)->i > 0)
	{
		(*iv)->current = *stack_a;
		(*iv)->max = INT_MIN;
		while ((*iv)->current)
		{
			if ((*iv)->max <= ft_atoi((*iv)->current->content)
				&& (*iv)->current->index == 0)
			{
				(*iv)->max = ft_atoi((*iv)->current->content);
				(*iv)->l_max = (*iv)->current;
			}
			(*iv)->current = (*iv)->current->next;
		}
		(*iv)->l_max->index = (*iv)->i;
		((*iv)->i)--;
		(*iv)->s_index = ft_itoa((*iv)->l_max->index);
		(*iv)->s_index1 = ft_strjoin((*iv)->s_index, "|");
		free((*iv)->s_index);
		(*iv)->s_index2 = ft_strjoin((*iv)->s_index1, (*iv)->l_max->content);
		free((*iv)->l_max->content);
		free((*iv)->s_index1);
		(*iv)->l_max->content = ft_strdup((*iv)->s_index2);
		free((*iv)->s_index2);
	}
}

void	index_stack(t_list **stack_a)
{
	t_index_var	iv;
	t_index_var	*_iv;

	iv.i = 0;
	iv.current = *stack_a;
	if (iv.current->next == NULL)
		_error(stack_a);
	while (iv.current)
	{
		iv.current->index = 0;
		iv.current = iv.current->next;
	}
	iv.i = ft_lstsize(*stack_a);
	_iv = &iv;
	index_stack2(&_iv, stack_a);
}
