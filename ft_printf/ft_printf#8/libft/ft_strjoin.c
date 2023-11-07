/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:43:22 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/23 13:09:32 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	dest = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (dest)
	{
		ft_strlcpy(dest, s1, ft_strlen(s1) + 1);
		ft_strlcpy(ft_strlen(s1) + dest, s2, ft_strlen(s2) + 1);
	}
	return (dest);
}
