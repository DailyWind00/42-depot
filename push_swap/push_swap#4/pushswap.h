/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:01:55 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/21 14:55:05 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
// J'aime les fonctions void :)
// main.c
void	error_exit(void);

// core.c
void	push_swap(int *pile_a, int size_a);

// swap.c
void	sa(int *pile_a, int size);
void	sb(int *pile_b, int size);
void	ss(int *pile_a, int size_a, int *pile_b, int size_b);

// push.c
void	pa(int *pile_a, int *size_a, int *pile_b, int *size_b);
void	pb(int *pile_a, int *size_a, int *pile_b, int *size_b);

// rotate.c
void	ra(int *pile_a, int size);
void	rb(int *pile_b, int size);
void	rr(int *pile_a, int size_a, int *pile_b, int size_b);

// reverse_rotate.c
void	rra(int *pile_a, int size);
void	rrb(int *pile_b, int size);
void	rrr(int *pile_a, int size_a, int *pile_b, int size_b);

// libft.c
void	ft_putstr_fd(const char *str, int fd);
int		ft_atoi(const char *str);

#endif
