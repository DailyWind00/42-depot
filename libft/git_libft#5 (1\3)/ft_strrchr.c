/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:37:20 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/19 11:16:03 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	while ((unsigned char)*s != (unsigned char)c)
	{
		s--;
		if (i < 0)
			return (0);
		i--;
	}
	return ((char *)s);
}
//debug
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char *test = "Hello 42 !";
	printf("%s\n", strrchr(test, 'l'));
	char *test2 = "Hello 42 !";
	printf("%s\n", ft_strrchr(test2, 'l'));
	return (0);
}
*/
