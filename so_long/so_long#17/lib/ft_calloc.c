/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:57:27 by aallou-v          #+#    #+#             */
/*   Updated: 2023/12/01 10:53:10 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*buffer;
	size_t	i;

	i = 0;
	buffer = malloc(nmemb * size);
	if (buffer == NULL)
		return (0);
	while (i != nmemb * size)
	{
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}
