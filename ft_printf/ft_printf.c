/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:59:37 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/04 14:06:12 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	get_conversion(const char *s, va_list args, int argn, int size)
{
	//homemade switch for all conversion types
	int		new_size;
	if (*s == c)
		new_size = ft_putchar(args, argn, size);
	else if (*s == s)
		new_size = ft_putstr(args, argn, size);
	else if (*s == p)
		new_size = ft_putptr(args, argn, size);
	else if (*s == d)
		new_size = ft_putdec(args, argn, size);
	else if (*s == i || *s == u) // To modify if don't work
		new_size = ft_putnbr(args, argn, size);
	else if (*s == x)
		new_size = ft_puthex(args, argn, size, 0); // ft_puthex take 0 for lowercase
	else if (*s == X)
		new_size = ft_puthex(args, argn, size, 1); // ft_puthex take 1 for huppercase
	else if (*s == %)
	{
		ft_putchar_fd('%', 1);
		new_size = size + 1;
	}
	return (new_size);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		argn;
	int		size;

	size = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			argn++;
			size = get_conversion(s + 1, args, argn, size);
		}
		else
			write(1, *s, 1);
		size++;
	}
	va_end(args);
	return (size);
}
