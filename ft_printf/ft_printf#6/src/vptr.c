/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vptr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:00:26 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/04 18:15:22 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvptr(long long unsigned int args, int size)
{
	int	vptr_size;

	vptr_size = 0;
	if (args == 0)
	{
		ft_putstr_fd("(nil)", 1);
		vptr_size = 5;
	}
	return (size + vptr_size);
}
