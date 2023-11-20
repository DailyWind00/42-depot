/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:25:01 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/20 15:18:06 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	core_ft(char **pile_a)
{
	int	i;
	int	b;
	int	buf;

	i = 0;
	b = 0;
	while (pile_a[i + 1])
	{
		buf = 0;
		while (ft_atoi(pile_a[buf]) <= ft_atoi(pile_a[buf + 1]))
		{
			if (!pile_a[buf + 2] && !b)
				exit(EXIT_SUCCESS);
			buf++;
		}
		if (ft_atoi(pile_a[i]) <= ft_atoi(pile_a[i + 1]))
		{
			ft_putstr_fd("pb\n", 1);
			i++;
			b++;
		}
		else
		{
			ft_putstr_fd("sa\n", 1);
			i++;
		}
	}
	while (b--)
		ft_putstr_fd("pa\n", 1);
}
// todo : really better sorting algorythm
