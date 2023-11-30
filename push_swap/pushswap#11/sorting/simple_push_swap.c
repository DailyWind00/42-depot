/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:34:45 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/30 10:34:46 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	hard_sort2(t_list **stack_a, int *nums)
{
	if (nums[0] < nums[1] && nums[1] < nums[2] && nums[0] < nums[2])
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	if (nums[0] > nums[1] && nums[1] < nums[2] && nums[0] < nums[2])
		ra(stack_a, 1);
	if (nums[0] > nums[1] && nums[1] < nums[2] && nums[0] > nums[2])
		sa(stack_a, 1);
	if (nums[0] < nums[1] && nums[1] > nums[2] && nums[0] < nums[2])
		rra(stack_a, 1);
	if (nums[0] < nums[1] && nums[1] > nums[2] && nums[0] > nums[2])
	{
		rra(stack_a, 1);
		sa(stack_a, 1);
	}
}

static void	hard_sort(t_list **stack_a, t_list **stack_b)
{
	int		nums[3];
	ssize_t	i;
	t_list	*current;

	(void) stack_b;
	i = -1;
	current = *stack_a;
	while (++i < 3)
	{
		nums[i] = ft_atoi(current->content);
		current = current->next;
	}
	hard_sort2(stack_a, nums);
}

static void	tiny_sort(t_list **stack_a, t_list **stack_b)
{
	int	pushed;

	pushed = 0;
	while (pushed != 2)
	{
		if (ft_atoi(ft_lstlast(*stack_a)->content) == 1
			|| ft_atoi(ft_lstlast(*stack_a)->content) == 2)
		{
			pushed++;
			pb(stack_a, stack_b);
		}
		else
			ra(stack_a, 1);
	}
	hard_sort(stack_a, stack_b);
	if (ft_atoi(ft_lstlast(*stack_b)->content) == 1)
		rb(stack_a, 1);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	simple_push_swap(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 3)
		hard_sort(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 5)
		tiny_sort(stack_a, stack_b);
}
