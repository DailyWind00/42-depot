/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 10:32:25 by mgallais          #+#    #+#             */
/*   Updated: 2023/07/23 10:33:13 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_itoal.h"

char	*ft_we_love_norme(long number, char **lines, char **av)
{
	char	*reference;

	reference = NULL;
	if (ft_strlen(av[1]) >= 7 && ft_strlen(av[1]) <= 9)
	{
		reference = str_from_alpha(lines, number / 1000000);
		ft_strcat(reference, " million");
	}
	else if (ft_strlen(av[1]) >= 10 && ft_strlen(av[1]) <= 12)
	{
		reference = str_from_alpha(lines, number / 1000000000);
		ft_strcat(reference, " billion");
	}
	return (reference);
}
