/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:08:40 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/07 11:10:49 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char args, int size)
{
	ft_putchar_fd((char)args, 1);
	return (size + 1);
}
//debug
/*
int	main(void)
{
	int	i = 1;

	i = ft_putchar('0', i);
	printf("%d", i);
	return (0);
}
*/
