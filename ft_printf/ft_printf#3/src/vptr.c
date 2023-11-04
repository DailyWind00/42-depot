/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vptr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:00:26 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/04 16:05:57 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putvptr(void *args, size)
{
	int	vptr_size;

	if (args == 0)
	{
		ft_putstr_fd("(nil)", 1);
		vptr_size = 5;
	}
	return (size + vptr_size)
}
