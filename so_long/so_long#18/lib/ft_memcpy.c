/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:49:23 by aallou-v          #+#    #+#             */
/*   Updated: 2023/10/17 19:38:06 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cd;
	unsigned char	*cs;

	i = -1;
	cd = (unsigned char *) dest;
	cs = (unsigned char *) src;
	if (cd == NULL && cs == NULL)
		return (NULL);
	while (++i < n)
		cd[i] = cs[i];
	return (dest);
}
