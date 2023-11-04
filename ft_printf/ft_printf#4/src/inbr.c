/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inbr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:49:28 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/04 18:14:51 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(int args)
{
	int	i;

	i = 1;
	if (args < 0)
	{
		i++;
		args = -args;
	}
	while (args / 10 > 0)
	{
		i++;
		args /= 10;
	}
	return (i);
}

int	ft_putinbr(int args, int size)
{
	ft_putnbr_fd(args, 1);
	return (size + ft_nbrlen(args));
}
