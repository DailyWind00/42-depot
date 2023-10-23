/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:10:16 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/23 16:30:23 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i + 1] == charset)
			words++;
		i++;
	}
	return (words);
}

static void	write_word(char *dest, char const *from, char charset)
{
	int	i;

	i = 0;
	while (from[i] != charset)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static void	write_split(char **split, char const *str, char charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == charset)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != charset)
				j++;
			split[word] = malloc(sizeof (char) * (j + 1));
			write_word(split[word], str + i, charset);
			
			i += j;
			word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	words = count_words(s, c);
	res = malloc(sizeof (char *) * (words + 1));
	res[words] = 0;
	write_split(res, s, c);
	return (res);
}
//debug
/*
#include <stdio.h>
int    main(void)
{
    int        i = -1;
    char    string[] = "                                  \" \"    ";
    char    **splits = ft_split(string, "\"");
    while (splits[++i])
        printf("%s\n", splits[i]);
    return (0);
}
*/

/*
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
*/
/*
static size_t	ft_count_split(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			j++;
		i++;
	}
	return (j);
}

static size_t	ft_size_counting(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
		i++;
	if (i == ft_strlen(s))
		return (0);
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	cur;
	char	**dest;

	i = 0;
	j = ft_count_split(s, c);
	cur = 0;
	dest = malloc(sizeof(char *) * (j + 1));
	if (dest)
	{
		while (i < j)
		{
			if (ft_size_counting(s, c))
			{
				size = ft_size_counting(s + cur, c);
				ft_strlcpy(dest[i], s + cur, size + 1);
				cur = ft_size_counting(s + cur, c);
			}
			i++;
		}
		dest[i] = NULL;
	}
	return (dest);
}
*/
