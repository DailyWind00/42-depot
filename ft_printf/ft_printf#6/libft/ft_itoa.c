/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:18:08 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/24 14:35:20 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_search_size(int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		size = 1;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while ((unsigned int)n != 0)
	{
		size++;
		n = (unsigned int)n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*dest;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_search_size(n);
	dest = malloc(sizeof(char) * (size + 1));
	if (dest)
	{
		if (n < 0)
		{
			*dest = '-';
			n = -n;
			i++;
		}
		dest[size] = 0;
		while (i < size)
		{
			dest[size - 1] = '0' + ((unsigned int)n % 10);
			n = (unsigned int)n / 10;
			size--;
		}
	}
	return (dest);
}
//debug
/*
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int		i;
	char	*buffer;

	printf ("Enter a number: ");
	scanf ("%d",&i);
	buffer = ft_itoa(i);
	printf ("decimal: %s\n",buffer);
	return (0);
}
*/
