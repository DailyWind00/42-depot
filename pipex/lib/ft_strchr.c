/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:29:04 by aallou-v          #+#    #+#             */
/*   Updated: 2023/10/19 16:28:21 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strchr(const char *s, int c)
// {
// 	while (*s)
// 	{
// 		if (*s == (char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if (!c)
// 		return ((char *)s);
// 	return (NULL);
// }

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (const char) c)
			return ((char *) s + i);
		i++;
	}
	if (s[i] == (const char) c)
		return ((char *) s + i);
	return (NULL);
}

// int	main(int argc, char **argv)
// {
// 	char	*test = ft_strchr2("teste", '\0');
// 	printf("%s\n", test);
// 	return (0);
// }
