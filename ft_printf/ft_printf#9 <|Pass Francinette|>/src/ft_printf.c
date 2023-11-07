/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:59:37 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/07 14:05:26 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_conversion(const char s, va_list args, int size)
{
	int		new_size;

	new_size = 0;
	if (s == 'c')
		new_size = ft_putchar(va_arg(args, int), size);
	else if (s == 's')
		new_size = ft_putstr(va_arg(args, char *), size);
	else if (s == 'p')
		new_size = ft_putvptr(va_arg(args, long long unsigned int), size);
	else if (s == 'd')
		new_size = ft_putinbr(va_arg(args, int), size);
	else if (s == 'i')
		new_size = ft_putinbr(va_arg(args, int), size);
	else if (s == 'u')
		new_size = ft_putunbr(va_arg(args, unsigned int), size);
	else if (s == 'x')
		new_size = ft_puthex(va_arg(args, unsigned int), size, 0);
	else if (s == 'X')
		new_size = ft_puthex(va_arg(args, unsigned int), size, 1);
	else if (s == '%')
	{
		ft_putchar_fd('%', 1);
		new_size = size + 1;
	}
	return (new_size);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		size;

	size = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			size = get_conversion(*(s + 1), args, size);
			s++;
		}
		else
		{
			write(1, &(*s), 1);
			size++;
		}
		s++;
	}
	va_end(args);
	return (size);
}
