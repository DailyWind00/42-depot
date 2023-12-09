/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:33:37 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/09 12:03:11 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_bin_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= 2;
	}
	return (i);
}

static int	get_max(t_list **stack_a)
{
	int		max;
	t_list	*current;

	max = INT_MIN;
	current = *stack_a;
	while (current)
	{
		if (ft_atoi(current->content) > max)
			max = ft_atoi(current->content);
		current = current->next;
	}
	return (max);
}

static void	push_swap(t_list **stack_a, t_list **stack_b)
{
	t_stacks_args	s_args;
	t_push_var		p_var;

	if (ft_lstsize(*stack_a) == 3 || ft_lstsize(*stack_a) == 5)
		simple_push_swap(stack_a, stack_b);
	else
	{
		p_var.j = 0;
		p_var.max = get_max(stack_a);
		p_var.n = count_bin_digits(p_var.max);
		s_args.stack_a = stack_a;
		s_args.stack_b = stack_b;
		while (p_var.j < p_var.n)
		{
			p_var.k = 0;
			p_var.i = ft_lstsize(*stack_a);
			radix(&(p_var.i), &s_args, p_var.j, &(p_var.k));
			while (p_var.k > 0)
			{
				pa(stack_a, stack_b);
				(p_var.k)--;
			}
			(p_var.j)++;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		check_args_str(argv);
		init_stack2(&stack_a, argv);
	}
	else
		init_stack(&stack_a, argc, argv);
	is_to_long(&stack_a);
	check_double(&stack_a);
	if (is_sorted(stack_a))
		_error(&stack_a);
	if (argc != 4 && argc != 6)
		index_stack(&stack_a);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
