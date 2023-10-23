/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:35:02 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/19 09:37:12 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t length)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	size_t			i;

	i = 0;
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (length <= 0)
		return (dest);
	while (i != length)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
//debug
//#include <string.h>
//#include <stdio.h>
//int	main(void)
//{
//	char	sptr[10] = "oooooooooo";
//	char	dptr[10] = "xxxxxxxxxx";
//	ft_memcpy(dptr, sptr, 7);
//	printf("%s\n", dptr);
//	memcpy(dptr, sptr, 7);
//	printf("%s\n", dptr);
//	return (0);
//}
