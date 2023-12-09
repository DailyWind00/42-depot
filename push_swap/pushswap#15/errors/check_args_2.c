/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:31:48 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/01 11:19:36 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_wspace(char c)
{
	if (c == 32 || c == 9 || c == 10
		|| c == 11 || c == 12 || c == 13)
		return (1);
	return (0);
}

void	check_args_str(char **argv)
{
	ssize_t	i;

	i = 0;
	if (!argv[1][1])
		exit(0);
	while (argv[1][i])
	{
		if (!is_wspace(argv[1][i]))
			return ;
		i++;
	}
	exit(0);
}
