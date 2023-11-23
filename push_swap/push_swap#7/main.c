/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:39:44 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/23 16:38:56 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pushswap.h"

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
			if (argv[j][i] != '-' && (argv[j][i] > '9' || argv[j][i] < '0'))
				error_exit();
			i++;
		}
		i = 0;
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*d;
	int		i;

	i = 0;
	error_handle(argc, argv);
	d->pile_a = malloc(sizeof(int) * argc - 1);
	if (!(d->pile_a))
		error_exit();
	d->pile_a[argc] = 0;
	while (i < argc - 1)
	{
		d->pile_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	push_swap(d);
	free(d);
	return (EXIT_SUCCESS);
}
