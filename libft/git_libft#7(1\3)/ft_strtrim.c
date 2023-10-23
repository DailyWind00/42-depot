/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:13:17 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/23 14:04:28 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	len;

	len = 0;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len - 1]))
		len--;
	dest = malloc(len + 1);
	if (dest)
		ft_strlcpy(dest, s1, len + 1);
	return (dest);
}
/*
static int	compare(char C, char const *set)
{
	while (*set != C && set)
		set++;
	if (*set == C)
		return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s1[i])
	{
		if (compare(s1[i], set))
			len++;
		i++;
	}
	i = 0;
	dest = malloc((sizeof(char) * len) + 1);
	while (s1[i])
	{
		if (compare(s1[i], set))
		{
			*dest = s1[i];
			dest++;
		}
		i++;
	}
	*dest = 0;
	return (dest);
}
*/
