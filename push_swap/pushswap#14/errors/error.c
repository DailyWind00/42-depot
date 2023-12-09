/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:32:21 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/05 15:29:57 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_error(t_list **stack)
{
	free_stack(stack);
	exit(0);
}

void	error(t_list **stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(0);
}

void	split_error(char **split_result)
{
	ft_free_split(split_result);
	ft_printf("Error\n");
	exit(0);
}
