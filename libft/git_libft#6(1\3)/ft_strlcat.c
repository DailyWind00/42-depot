/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:36:33 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/18 18:14:23 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	if (size == 0)
		return (ft_strlen(src));
	else if (size - 1 < i)
		return (size + ft_strlen(src));
	else
	{
		while (src[j] && i + j < (size - 1))
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = 0;
	}
	return (i + ft_strlen(src));
}
//debug
//In strlcat, you return the length of dest plus the length of src
/*
#include <string.h>
#include <stdio.h>
int main()
{
    char first[] = "This is ";
    char last[] = "a potentially long string";
    int r;
    int size = 42;
    char buffer[size];

    strcpy(buffer, first);
    r = ft_strlcat(buffer,last,size);

    printf("%s\n", buffer);
    printf("Value returned: %d\n",r);
    if(r > size)
        printf("String truncated\n");
    else
        printf("String was fully copied\n");

    return(0);
}
*/
