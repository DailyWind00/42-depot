/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:34:54 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/09 12:45:57 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	ssize_t	count_nbr(char const *s)
{
	ssize_t	i;
	ssize_t	last;
	ssize_t	ctr;

	i = 0;
	last = 1;
	ctr = 0;
	while (s[i])
	{
		if (last && s[i] != ' ')
		{
			last = 0;
			ctr++;
		}
		else if (!last && s[i] == ' ')
			last = 1;
		i++;
	}
	return (ctr);
}

int	is_a_number(char const *s)
{
	size_t	i;

	i = 0;
	if (!(s[0] >= '0' && s[0] <= '9'))
		if (s[0] != '-')
			return (0);
	while (s[++i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
	}
	return (1);
}

static void	puteuuuh(t_list **stack_a, t_init_stack2_var is,
												char **split_result)
{
	while ((is.i)-- >= 1)
	{
		is.j = -1;
		if (!is_a_number(split_result[is.i]))
			split_error(split_result);
		is.current = ft_lstnew(ft_strdup(split_result[is.i]));
		if (!(is.current))
		{
			ft_free_split(split_result);
			return ;
		}
		ft_lstadd_back(stack_a, is.current);
	}
	ft_free_split(split_result);
}

void	init_stack2(t_list **stack_a, char **argv)
{
	t_init_stack2_var	is;
	char				**split_result;

	is.j = -1;
	is.i = count_nbr(argv[1]);
	split_result = ft_split(argv[1], ' ');
	if (!is_a_number(split_result[is.i - 1]))
		split_error(split_result);
	*stack_a = ft_lstnew(ft_strdup(split_result[is.i - 1]));
	if (!(*stack_a))
		return ;
	(is.i)--;
	puteuuuh(stack_a, is, split_result);
}

void	init_stack(t_list **stack_a, int argc, char **argv)
{
	t_list	*current;
	ssize_t	i;

	i = argc - 2;
	if (!is_a_number(argv[argc - 1]))
		error(stack_a);
	*stack_a = ft_lstnew(ft_strdup(argv[argc - 1]));
	if (!(*stack_a))
		return ;
	while (i >= 1)
	{
		if (!is_a_number(argv[i]))
			error(stack_a);
		current = ft_lstnew(ft_strdup(argv[i]));
		if (!current)
			return ;
		ft_lstadd_back(stack_a, current);
		i--;
	}
}
