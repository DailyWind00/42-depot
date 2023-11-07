/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:25:07 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/04 18:14:45 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_search_size(int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		size = 1;
	while (n != 0)
	{
		size++;
		n = n / 16;
	}
	return (size);
}

int	ft_itohex(unsigned int n, int format)
{
	const char	*lowercase;
	const char	*uppercase;
	char		*dest;
	size_t		size;
	size_t		i;

	lowercase = "0123456789abcdef";
	uppercase = "0123456789ABCDEF";
	i = 0;
	size = ft_search_size(n);
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (0);
	dest[size] = 0;
	while (i < size)
	{
		if (format == 0)
			dest[size - 1] = *lowercase + (n % 16);
		else if (format == 1)
			dest[size - 1] = *uppercase + (n % 16);
		n = n / 16;
		size--;
	}
	ft_putstr_fd(dest, 1);
	return (ft_search_size(n));
}

int	ft_puthex(unsigned long args, int size, int format)
{
	int	hex_size;

	hex_size = ft_itohex(args, format);
	return (size + hex_size);
}
