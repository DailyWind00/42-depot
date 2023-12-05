/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:32:38 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/01 15:21:19 by mgallais         ###   ########.fr       */
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
