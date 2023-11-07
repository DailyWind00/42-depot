/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:13:35 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/26 15:36:12 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	**cur;
	void	*content;

	first = NULL;
	cur = &first;
	while (lst)
	{
		content = (*f)(lst->content);
		*cur = ft_lstnew(content);
		if (!*cur)
		{
			ft_lstclear(&first, del);
			(*del)(content);
			return (NULL);
		}
		cur = &(*cur)->next;
		lst = lst->next;
	}
	return (first);
}
