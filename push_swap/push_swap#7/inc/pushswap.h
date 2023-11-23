/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:01:55 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/23 16:37:50 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_list
{
	int	*pile_a;
	int	*size_a;
	int	*pile_b;
	int	*size_b;
}	t_list;

// main.c //
void	error_exit(void);

// sort.c //
void	push_swap(t_list *d);

// swap.c //
void	sa(t_list d, bool single);
void	sb(t_list d, bool single);
void	ss(t_list d);

// push.c //
void	pa(t_list d);
void	pb(t_list d);

// rotate.c //
void	ra(t_list d, bool single);
void	rb(t_list d, bool single);
void	rr(t_list d);

// reverse_rotate.c //
void	rra(t_list d, bool single);
void	rrb(t_list d, bool single);
void	rrr(t_list d);

// libft.c //
void	ft_putstr_fd(const char *str, int fd);
int		ft_atoi(const char *str);

#endif
