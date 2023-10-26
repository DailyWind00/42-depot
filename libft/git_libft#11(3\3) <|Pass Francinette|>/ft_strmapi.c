/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:14:20 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/24 15:40:51 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dest)
	{
		while (s[i])
		{
			dest[i] = (*f)(i, s[i]);
			i++;
		}
		dest[i] = 0;
	}
	return (dest);
}
