/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:39:51 by aallou-v          #+#    #+#             */
/*   Updated: 2023/10/30 02:53:57 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_base_fd(unsigned long nb, char *base, int fd)
{
	if (nb / 16)
		ft_putnbr_base_fd(nb / 16, base, fd);
	ft_putchar_fd(base[nb % 16], fd);
}

int	ft_printf_x(char current, va_list ap)
{
	unsigned int	values;
	char			*base;

	if (current != 'x' && current != 'X')
		return (0);
	values = va_arg(ap, unsigned int);
	base = "0123456789abcdef";
	if (current == 'X')
		base = "0123456789ABCDEF";
	ft_putnbr_base_fd(values, base, FD);
	return (ft_count_hex_digits(values));
}

static int	ft_print_ptr(void *ptr)
{
	unsigned long	l_ptr;

	l_ptr = *(unsigned long *)&ptr;
	if (l_ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd(l_ptr, "0123456789abcdef", FD);
	return (ft_count_hex_digits(l_ptr) + 2);
}

int	ft_printf_p(char current, va_list ap)
{
	if (current == 'p')
		return (ft_print_ptr(va_arg(ap, void *)));
	return (0);
}
