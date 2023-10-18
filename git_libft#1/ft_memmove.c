/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:26:15 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/17 14:56:52 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, int length)
{
	int				i;
	unsigned char	*cdest;
	unsigned char	*csrc;
	unsigned char	*buffer;

	i = 0;
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	buffer = (unsigned char *)src;
	if (dest == 0 || src == 0 || length <= 0)
		return (0);
	while (i != length)
	{
		buffer[i] = csrc[i];
		i++;
	}
	i = 0;
	while (i != length)
	{
		cdest[i] = buffer[i];
		i++;
	}
	return (dest);
}
//debug
//#include <string.h>
//#include <stdio.h>
//int main() 
//{
//	char csrc[100] = "Geeksfor";
//	ft_memmove(csrc + 3, csrc, strlen(csrc) + 1);
//	printf("%s\n", csrc);
//	char csrc2[100] = "Geeksfor";
//	memmove(csrc2 + 3, csrc2, strlen(csrc2) + 1);
//	printf("%s\n", csrc);
//	return (0);
//}
