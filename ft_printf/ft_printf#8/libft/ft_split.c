/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:10:16 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/30 14:43:00 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_the_fucking_splits(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	**dest;

	i = 0;
	j = count_the_fucking_splits(s, c);
	dest = malloc(sizeof(char *) * (j + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (j < count_the_fucking_splits(s, c))
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		dest[j] = ft_strndup(s + start, i - start);
		if (!dest[j])
			return (NULL);
		j++;
	}
	dest[j] = NULL;
	return (dest);
}
//debug
/*
#include <stdio.h>
int    main(void)
{
    int        i = -1;
    char    string[] = "Hello l'ecole 42";
    char    **splits = ft_split(string, ' ');
    while (splits[++i])
        printf("%s\n", splits[i]);
    return (0);
}
*/
