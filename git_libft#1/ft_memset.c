/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:38:14 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/17 13:02:52 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *vptr, int value, unsigned int count)
{
	unsigned char	*cptr;

	cptr = vptr;
	if (vptr == 0 || count == 0)
		return (vptr);
	while (count--)
		*cptr++ = (unsigned char)value;
	return (vptr);
}
//debug
//#include <string.h>
//#include <stdio.h>
//int	main(void)
//{
//	char	vptr[10] = "jiegojkjhh";
//	ft_memset(vptr, "_", 1);
//	printf("%s\n", vptr);
//	memset(vptr, "_", 1);
//	printf("%s\n", vptr);
//	return (0);
//}
