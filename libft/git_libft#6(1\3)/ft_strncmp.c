/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:00:40 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/19 09:53:35 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while ((cs1 && *cs1) && (cs2 && cs2) && *cs1 == *cs2 && n != 0)
	{
		cs1++;
		cs2++;
		n--;
	}
	if (n != 0)
		return (*cs1 - *cs2);
	return (0);
}
//debug
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	const char	*s1 = "abcdeFGH";
	const char	*s2 = "abcdefgh";
	printf("%i\n", ft_strncmp(s1, s2, 10));
	printf("%i\n", strncmp(s1, s2, 10));
	return (0);
}
*/
