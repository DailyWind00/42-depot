/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:55:22 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/30 12:02:25 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cs;

	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	cs = malloc(len + 1);
	if (cs)
		ft_strlcpy(cs, (char *)s + start, len + 1);
	return (cs);
}
//debug
/*
int main()
{
    char src[] = "substr function Implementation";
 
    int m = 7;
    int n = 12;
 
    char* dest = substr(src, m, n);
 
    printf("%s\n", dest);
 
    return 0;
}
*/
