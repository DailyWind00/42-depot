/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:30:45 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/30 12:16:37 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strndup(const char *s, size_t n)
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
//debug
/*
#include <stdio.h>
int		main(void)
{
	char nas[10] = "test";
	printf("%s", ft_strdup(nas));
	return (0);
}
*/
