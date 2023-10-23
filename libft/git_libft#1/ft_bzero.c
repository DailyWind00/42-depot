/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:38:18 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/17 14:53:26 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_bzero(void *dst, int n)
{
	unsigned char	*cptr;

	cptr = dst;
	if (dst == 0 || n <= 0)
		return (dst);
	while (n--)
		*cptr++ = 0;
	return (dst);
}
//debug
//#include <string.h>
//#include <stdio.h>
//int	main(void)
//{
//	char	vptr[10] = "jiegojkjhh";
//	ft_bzero(vptr, 3);
//	printf("%s\n", vptr);
//	bzero(vptr, 3);
//	printf("%s\n", vptr);
//	return (0);
//}
