/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:25:01 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/20 13:51:24 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	core_ft(char **pile_a)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (pile_a[i + 1])
	{
		if (ft_atoi(pile_a[i]) <= ft_atoi(pile_a[i + 1]))
		{
			ft_putstr_fd("pa\n", 1);
			i++;
		}
		else
		{
			ft_putstr_fd("sa\npb\n", 1);
			i++;
			b++;
		}
	}
	while (b--)
		ft_putstr_fd("pa\n", 1);
}
