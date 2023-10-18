/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:15:14 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/18 12:31:58 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}
//debug
//In strlcpy, you return the length of src
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	int		size = 12; // Change size to see changes
	char	string[] = "Hello there, 42";
	char	buffer[16];
	int 	r;

	r = ft_strlcpy(buffer, string, size);
	printf("Copied '%s' into '%s', length %d\n", string, buffer, r);
}
*/
