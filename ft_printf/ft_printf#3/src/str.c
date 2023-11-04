/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:39:32 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/04 14:45:52 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_strlen(char *args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	ft_putstr(char *args, int size)
{
	ft_putstr_fd(args, 1);
	return (size + ft_strlen(args));
}
