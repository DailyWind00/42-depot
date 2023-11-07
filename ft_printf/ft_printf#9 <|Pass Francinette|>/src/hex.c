/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:25:07 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/07 14:05:02 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex(unsigned int num, int format)
{
	int	i;

	i = 0;
	if (num >= 16)
	{
		i += ft_hex(num / 16, format);
		i += ft_hex(num % 16, format);
	}
	else
	{
		if (format == 0)
			ft_putchar_fd(*(LOWERCASE + (num % 16)), 1);
		else if (format == 1)
			ft_putchar_fd(*(UPPERCASE + (num % 16)), 1);
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned int args, int size, int format)
{
	int	hexsize;

	hexsize = ft_hex(args, format);
	return (size + hexsize);
}
