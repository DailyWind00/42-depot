/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:27:54 by aallou-v          #+#    #+#             */
/*   Updated: 2023/10/17 14:56:36 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		mctr;
	int		res;

	i = 0;
	mctr = 0;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			mctr++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = (res * 10) + (nptr[i++] - 48);
	if (mctr % 2 != 0)
		return (-res);
	return (res);
}
