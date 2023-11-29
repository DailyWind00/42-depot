/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_to_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:49:53 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/24 15:38:39 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error(t_list **stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(0);
}

static int	ft_atolv(const char *nptr)
{
	size_t	i;
	int		mctr;
	long	res;

	i = 0;
	mctr = 0;
	res = 0;
	if (ft_strncmp(nptr, "-2147483648", 10) == 0)
		return (1);
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			mctr++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i++] - 48);
		if (res > 2147483647)
			return (0);
	}
	if (mctr % 2 != 0)
		return (1);
	return (1);
}

void	is_to_long(t_list **stack_a)
{
	int		is_neg;
	char	*s;
	t_list	*current;

	current = *stack_a;
	while (current)
	{
		is_neg = 0;
		s = current->content;
		if (s[0] == '-')
			is_neg = 1;
		if (ft_atoi(current->content) < 0 && !is_neg)
			error(stack_a);
		if (ft_atoi(current->content) >= 0 && is_neg)
			error(stack_a);
		if (!ft_atolv(current->content))
			error(stack_a);
		current = current->next;
	}
}
