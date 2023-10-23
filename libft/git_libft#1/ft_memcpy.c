/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:35:02 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/17 14:56:03 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, int length)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	int				i;

	i = 0;
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	if (dest == 0 || src == 0 || length <= 0)
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
