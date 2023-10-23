/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:33:43 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/19 15:37:14 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*buffer;
	size_t	i;

	i = 0;
	buffer = malloc(nmemb * size);
	if (buffer == NULL)
		return (0);
	while (i != nmemb * size)
	{
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}
//debug
/*
#include <stdlib.h>
#include <stdio.h>
int main( void )
{
    char* buffer;

    buffer = (char* )ft_calloc( 80, sizeof(char) );
    if( buffer == NULL ) {
        printf( "Can't allocate memory for buffer!\n" );
        return EXIT_FAILURE;
    }

    free( buffer );

    return EXIT_SUCCESS;
}
*/
