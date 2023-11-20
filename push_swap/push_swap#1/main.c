/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:39:44 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/20 13:54:45 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static void	error_handle(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (argc == 1)
		error_exit();
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][j] != '-' && (argv[j][i] > '9' || argv[j][i] < '0'))
				error_exit();
			i++;
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	char	*pile_b;

	error_handle(argc, argv);
	core_ft(argv + 1);
	return (EXIT_SUCCESS);
}
