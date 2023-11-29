/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:10:55 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/24 13:55:22 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_ft_lstdelone(t_list *lst)
{
	if (lst)
	{
		free(lst->content);
		free(lst);
	}
}

static void	_ft_lstclear(t_list **lst)
{
	t_list	*next;
	t_list	*current;

	current = *lst;
	while (current)
	{
		next = current->next;
		_ft_lstdelone(current);
		current = next;
	}
	*lst = NULL;
}

void	free_stack(t_list **stack)
{
	_ft_lstclear(stack);
	free(*stack);
}
