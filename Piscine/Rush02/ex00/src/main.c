/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleveill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 09:12:50 by hleveill          #+#    #+#             */
/*   Updated: 2023/07/23 10:26:05 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_itoal.h"

void	free_da_vars(char **lines, char *reference)
{
	free(reference);
	while (*lines)
		free(*lines++);
}

int	process_input(char **av)
{
	long	number;
	char	**lines;
	char	*reference;

	number = ft_atol(av[1]);
	if (number < 0 || !ft_is_numeric(av[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	lines = get_lines(DICT_PATH);
	if (!lines)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	reference = ft_proccess_number(number, lines, av);
	if (!reference)
	{
		ft_putstr("Error\n");
		return (0);
	}
	ft_putstr(reference);
	free_da_vars(lines, reference);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!process_input(av))
			return (0);
	}
	else if (ac == 3)
	{
		if (!append_entry(av[1], av[2]))
			ft_putstr("Dict Error\n");
		return (0);
	}
	ft_putstr("\n");
	return (0);
}
