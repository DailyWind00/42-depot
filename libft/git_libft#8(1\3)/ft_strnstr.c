/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:23:36 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/19 09:28:53 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!little[0])
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j]
			&& i + j < len && big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
//debug
/*
#include <string.h>
#include <stdio.h>
int main() {
    char	*big = "Hello, world! This is a test.";
    char	*little = "world";

    char	*result = ft_strnstr(big, little, strlen(big));

    if (result != NULL) {
        printf("little found at position: %ld\n", result - big);
    } else {
        printf("little not found.\n");
    }

    return 0;
}
*/
