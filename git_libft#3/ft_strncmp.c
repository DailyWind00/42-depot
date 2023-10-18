/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:00:40 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/18 12:33:29 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n != 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
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
