/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:33:14 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/09 12:00:23 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# include <limits.h>
# include <strings.h>

typedef struct s_index_var
{
	int		max;
	t_list	*current;
	t_list	*l_max;
	ssize_t	i;
	char	*s_index;
	char	*s_index1;
	char	*s_index2;
}	t_index_var;

typedef struct s_stacks_args
{
	t_list	**stack_a;
	t_list	**stack_b;
}	t_stacks_args;

typedef struct s_push_var
{
	int	i;
	int	j;
	int	k;
	int	max;
	int	n;
}	t_push_var;

typedef struct s_init_stack2_var
{
	t_list	*current;
	ssize_t	i;
	ssize_t	j;
}	t_init_stack2_var;

//	op.c
void	sa(t_list **stack_a, int d);
void	sb(t_list **stack_b, int d);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a, int d);
void	rb(t_list **stack_b, int d);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a, int d);
void	rrb(t_list **stack_b, int d);
void	rrr(t_list **stack_a, t_list **stack_b);
//	stack.c
void	init_stack(t_list **stack_a, int argc, char **argv);
void	init_stack2(t_list **stack_a, char **argv);
//	free_stack.c
void	free_stack(t_list **stack);
//	radix.c
void	radix(int *i, t_stacks_args *s_args, int j, int *k);
//	indexing.c
void	index_stack(t_list **stack_a);
//	check_double.c
void	check_double(t_list **stack_a);
//	is_to_long.c
void	is_to_long(t_list **stack_a);
//	is_sorted.c
int		is_sorted(t_list *stack_a);
//	error.c
void	_error(t_list **stack);
void	error(t_list **stack);
void	split_error(char **split_result);
//	check_args_2.c
void	check_args_str(char **argv);
//	simple_push_swap
void	simple_push_swap(t_list **stack_a, t_list **stack_b);
#endif
