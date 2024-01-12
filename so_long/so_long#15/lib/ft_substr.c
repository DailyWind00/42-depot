/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:37:54 by aallou-v          #+#    #+#             */
/*   Updated: 2023/10/19 20:52:46 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check(void)
{
	char	*substr;

	substr = malloc(sizeof(char));
	if (!substr)
		return (NULL);
	*substr = 0;
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	values;

	if (start >= ft_strlen(s))
		return (ft_check());
	if (ft_strlen(s) - start >= len)
		substr = ft_calloc(len + 1, sizeof(char));
	else
		substr = ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = start;
	values = 0;
	while (s[i])
	{
		if (values >= len)
			break ;
		substr[values] = s[i];
		values++;
		i++;
	}
	substr[values] = 0;
	return (substr);
}

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	char	v1[] = "hola";
// 	char	*v2;
// 	v2 = ft_substr(v1, 0, 10);
// 	printf("%s / %s\n", v1, v2);
// }
