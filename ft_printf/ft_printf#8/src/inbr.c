/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inbr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:49:28 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/07 12:11:01 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putinbr(int args, int size)
{
	if (args < 0)
	{
		ft_putchar_fd('-', 1);
		size++;
		args = -args;
	}
	size = ft_putunbr(args, size);
	return (size);
}
