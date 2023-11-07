/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:39:32 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/07 11:48:38 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *args, int size)
{
	if (!args)
	{
		ft_putstr_fd("(null)", 1);
		return (size + 6);
	}
	ft_putstr_fd(args, 1);
	return (size + ft_strlen(args));
}
