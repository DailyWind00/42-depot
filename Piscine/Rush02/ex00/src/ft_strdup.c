/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleveill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:47:59 by hleveill          #+#    #+#             */
/*   Updated: 2023/07/23 14:48:22 by hleveill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_itoal.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = -1;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[++i])
	{
		dest[i] = src[i];
	}
	return (dest);
}
