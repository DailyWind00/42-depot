/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:13:23 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/07 14:05:57 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define LOWERCASE "0123456789abcdef"
# define UPPERCASE "0123456789ABCDEF"
# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(char args, int size);
int	ft_puthex(unsigned int args, int size, int format);
int	ft_putinbr(int args, int size);
int	ft_putstr(char *args, int size);
int	ft_putunbr(unsigned int args, int size);
int	ft_putvptr(long long unsigned int args, int size);
#endif
