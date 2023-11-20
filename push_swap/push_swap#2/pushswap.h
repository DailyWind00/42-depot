/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:01:55 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/20 13:53:27 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>

// main.c
void	error_exit(void);

// core.c
void	core_ft(char **pile_a);

// libft.c
void	ft_putstr_fd(const char *str, int fd);
int		ft_atoi(const char *str);

#endif
