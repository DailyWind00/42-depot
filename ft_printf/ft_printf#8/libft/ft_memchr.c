/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:26:01 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/19 11:16:41 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*cs;

	cs = (unsigned char *)s;
	while (n > 0)
	{
		if (*cs == (unsigned char)c)
			return (cs);
		cs++;
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
    char* where;

    strcpy( buffer, "video x-rays" );

    where = (char *) ft_memchr( buffer, 'x', 6 );
    if( where == NULL ) {
        printf( "'x' not found\n" );
    } else {
        printf( "%s\n", where );
    }

    where = (char *) ft_memchr( buffer, 'r', 9 );
    if( where == NULL ) {
        printf( "'r' not found\n" );
    } else {
        printf( "%s\n", where );
    }
    
    return EXIT_SUCCESS;
}
*/
