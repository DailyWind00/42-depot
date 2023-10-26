/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:10:16 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/24 12:16:46 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **split, size_t i)
{
	while (i--)
		free(split[i]);
	free(split);
	return (NULL);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*dst;

	len = 0;
	while (len < n && s[len])
		len++;
	dst = malloc(len + 1);
	if (dst)
		ft_strlcpy(dst, s, len + 1);
	return (dst);
}

static char	*ft_next_word(char const *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return ((char *)s);
}

static size_t	ft_split_count(char const *s, char c)
{
	size_t		count;
	char const	*cur;

	cur = s;
	count = 0;
	while (*cur)
	{
		cur = ft_next_word(s, c);
		if (0 < cur - s)
			count++;
		s = cur + 1;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	char const	*cur;
	size_t		i;
	size_t		j;

	i = 0;
	j = ft_split_count(s, c);
	split = malloc(sizeof(char *) * (j + 1));
	if (split)
	{
		while (i < j)
		{
			cur = ft_next_word(s, c);
			if (0 < cur - s)
			{
				split[i] = ft_strndup(s, cur - s);
				if (!split[i])
					return (ft_free(split, i));
				i++;
			}
			s = cur + 1;
		}
		split[i] = NULL;
	}
	return (split);
}
//debug
/*
#include <stdio.h>
int    main(void)
{
    int        i = -1;
    char    string[] = "Hello l'ecole 42";
    char    **splits = ft_split(string, " ");
    while (splits[++i])
        printf("%s\n", splits[i]);
    return (0);
}
*/
