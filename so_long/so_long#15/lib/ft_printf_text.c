/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:29:01 by aallou-v          #+#    #+#             */
/*   Updated: 2023/10/30 02:53:57 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_s(char current, va_list ap)
{
	char	*str;

	if (current != 's')
		return (ft_printf_c(current, ap));
	str = va_arg(ap, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", FD);
		return (6);
	}
	ft_putstr_fd(str, FD);
	return (ft_strlen(str));
}

int	ft_printf_c(char current, va_list ap)
{
	if (current == 'c')
	{
		ft_putchar_fd(va_arg(ap, int), FD);
		return (1);
	}
	return (ft_printf_pourcent(current));
}

int	ft_printf_pourcent(char current)
{
	if (current == '%')
	{
		ft_putchar_fd('%', FD);
		return (1);
	}
	return (0);
}
