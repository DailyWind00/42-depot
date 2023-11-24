/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:39:44 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/24 16:07:56 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/pushswap.h"

void	error_exit(t_list d)
{
	ft_free(d);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static void	error_handle(int argc, char **argv, t_list d)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (argc == 1)
		error_exit(d);
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] != '-' && (argv[j][i] > '9' || argv[j][i] < '0'))
				error_exit(d);
			i++;
		}
		i = 0;
		j++;
	}
}

static void	check_doublon(t_list d)
{
	int	i;
	int	j;
	int	buf;

	i = 0;
	j = 0;
	while (i++ != d->size_a)
	{
		buf = d->pile_a[i];
		while (j++ <= d->size_a)
			if (d->size_a[j] == buf && i != j)
				error_exit(d);
	}
}

static s_list	make_struct(int argc, char **argv, t_list d)
{
	int	i;

	i = 0;
	d->pile_a = malloc(sizeof(int) * argc - 1);
	d->pile_b = malloc(sizeof(int) * argc - 1);
	if (!(d->pile_a) || !(d->pile_b))
		error_exit(d);
	while (i++ < argc - 1)
		d->pile_a[i] = ft_atoi(argv[i + 1]);
	d->size_a = argc - 1;
	d->size_b = 0;
}

int	main(int argc, char **argv)
{
	t_list	*d;

	error_handle(argc, argv, d);
	d = make_struct(argc, argv, d);
	check_doublon(d);
	sorting(d);
	ft_free(d);
	return (EXIT_SUCCESS);
}
