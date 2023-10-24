/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:55:22 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/24 16:20:55 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	src_len;

	src_len = ft_strlen(s);
	start = ft_min(src_len, start);
	len = ft_min(src_len - start, len);
	dst = malloc(len + 1);
	if (dst)
		ft_strlcpy(dst, s + start, len + 1);
	return (dst);
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
