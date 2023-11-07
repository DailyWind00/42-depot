/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vptr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:00:26 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/07 13:53:43 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_void(unsigned long long int num)
{
	int	i;

	i = 0;
	if (num >= 16)
	{
		i += ft_hex_void(num / 16);
		i += ft_hex_void(num % 16);
	}
	else
	{
		ft_putchar_fd(*(LOWERCASE + (num % 16)), 1);
		i++;
	}
	return (i);
}

int	ft_putvptr(unsigned long long int num, int size)
{
	int	i;

	i = 0;
	if (num > 0)
	{
		write(1, "0x", 2);
		i += 2;
	}
	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (size + 5);
	}
	i += ft_hex_void(num);
	return (size + i);
}
