/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unbr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:06:38 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/04 15:11:18 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_unbrlen(unsigned int args)
{
	int	i;

	i = 1;
	while (args / 10 > 0)
	{
		i++;
		args /= 10;
	}
	return (i);
}

int	ft_putunbr(unsigned int args, int size)
{
	ft_putunbr_fd(args, 1);
	return (size + ft_unbrlen(args));
}
