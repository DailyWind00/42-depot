/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:25:37 by aallou-v          #+#    #+#             */
/*   Updated: 2023/10/17 18:30:04 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cs;

	cs = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char) c == cs[i])
			return (&cs[i]);
		i++;
	}
	return (NULL);
}
