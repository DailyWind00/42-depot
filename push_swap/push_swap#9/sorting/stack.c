/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:58:14 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/24 15:50:30 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error(void)
{
	ft_printf("Error\n");
	exit(0);
}

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

void	init_stack2(t_list **stack_a, char **argv)
{
	t_init_stack2_var	is;

	is.j = -1;
	is.i = count_nbr(argv[1]);
	if (!(*stack_a))
		return ;
	argv = ft_split(argv[1], ' ');
	if (!is_a_number(argv[is.i - 1]))
		error();
	*stack_a = ft_lstnew(ft_strdup(argv[is.i - 1]));
	(is.i)--;
	while (is.i >= 1)
	{
		is.j = -1;
		if (!is_a_number(argv[is.i - 1]))
			error();
		is.current = ft_lstnew(ft_strdup(argv[is.i - 1]));
		if (!(is.current))
			return ;
		ft_lstadd_back(stack_a, is.current);
		(is.i)--;
	}
}

void	init_stack(t_list **stack_a, int argc, char **argv)
{
	t_list	*current;
	ssize_t	i;

	i = argc - 2;
	if (!is_a_number(argv[argc - 1]))
		error();
	*stack_a = ft_lstnew(ft_strdup(argv[argc - 1]));
	if (!(*stack_a))
		return ;
	while (i >= 1)
	{
		if (!is_a_number(argv[i]))
			error();
		current = ft_lstnew(ft_strdup(argv[i]));
		if (!current)
			return ;
		ft_lstadd_back(stack_a, current);
		i--;
	}
}
