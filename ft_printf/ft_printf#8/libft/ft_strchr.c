/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:20:41 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/19 11:14:42 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && (unsigned char)*s != (unsigned char)c)
		s++;
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
//debug
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char *test = "Hello 42 !";
	printf("%s\n", strchr(test, 'o'));
	char *test2 = "Hello 42 !";
	printf("%s\n", ft_strchr(test2, 'o'));
	return (0);
}
*/
