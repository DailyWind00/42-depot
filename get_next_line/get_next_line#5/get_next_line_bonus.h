/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:19:59 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/10 15:46:24 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// get_next_line.c
char	*get_next_line(int fd);

// get_next_line_utils.c (libft)
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(char *s);

#endif
