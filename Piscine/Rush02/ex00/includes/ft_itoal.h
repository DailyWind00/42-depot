/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 10:39:17 by mgallais          #+#    #+#             */
/*   Updated: 2023/07/23 15:20:54 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITOAL_H
# define FT_ITOAL_H
# define DICT_PATH "./numbers.dict"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_is_numeric(char *str);
long	ft_atol(char *str);
void	ft_strcat(char *dest, char *src);
char	*ft_strdup(char *src);
char	**get_lines(char *path);
char	*ft_proccess_number(long number, char **lines, char **av);
char	*str_from_alpha(char **lines, long nb);
int		append_entry(char *nb, char *ref);
char	*ft_we_love_norme(long number, char **lines, char **av);

#endif
