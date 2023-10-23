/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:43:09 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/18 12:26:41 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (n != 0)
	{
		if (*cs1 != *cs2)
			return (*cs1 - *cs2);
		cs1++;
		cs2++;
		n--;
	}
	return (0);
}
//debug
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main( void )
{
    char buffer[80];
    int retval;

    strcpy( buffer, "World" );
    
    retval = ft_memcmp( buffer, "Hello", 5 );
    if( retval < 0 ) {
        printf( "Less than\n" );
    } else if( retval == 0 ) {
        printf( "Equal to\n");
    } else {
        printf( "Greater than\n");
    }
    
    return EXIT_SUCCESS;
}
*/
