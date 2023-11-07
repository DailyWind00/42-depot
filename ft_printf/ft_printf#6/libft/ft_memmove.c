/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:26:15 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/20 16:47:54 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cdest;
	unsigned char	*csrc;

	cdest = (unsigned char *) dest;
	csrc = (unsigned char *) src;
	if (!dest && !src && n > 0)
		return (NULL);
	if (dest > src && dest < src + n)
	{
		i = n;
		while (i-- > 0)
			cdest[i] = csrc[i];
	}
	else
	{
		i = -1;
		while (++i < n)
			cdest[i] = csrc[i];
	}
	return (dest);
}
//debug
/*
#include <string.h>
#include <stdio.h>
int main() 
{
	char csrc[100] = "Geeksfor";
	ft_memmove(csrc + 3, csrc, strlen(csrc) + 1);
	printf("%s\n", csrc);
	char csrc2[100] = "Geeksfor";
	memmove(csrc2 + 3, csrc2, strlen(csrc2) + 1);
	printf("%s\n", csrc);
	return (0);
}
*/
