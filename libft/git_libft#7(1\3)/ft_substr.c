/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:55:22 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/23 13:33:59 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cs;

	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s);
	cs = malloc(len + 1);
	if (cs)
		ft_strlcpy(cs, (char *)s + start, len + 1);
	return (cs);
}
/*
{
	char	*cs;
	size_t	i;

	i = 0;
	if (!s)
		return ((char *)s);
	cs = malloc(sizeof(char) * (len - start + 1));
	if (!cs || (len - start) > ft_strlen(s))
		return (cs);
	while (s[start] && cs && len > 0)
	{
		cs[i] = s[start];
		start++;
		i++;
		len--;
		if (start > ft_strlen(s))
			return (cs);
	}
	cs[i] = '\0';
	return (cs);
}
*/
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
