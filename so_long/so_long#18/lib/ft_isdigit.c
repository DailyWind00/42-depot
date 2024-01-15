/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:09:33 by aallou-v          #+#    #+#             */
/*   Updated: 2023/10/17 14:56:36 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
#include "unistd.h"

int main(int argc, char **argv)
{
	int values = ft_isdigit(48);
	if (values == 1)
	{
		write(1, "1", 1);
		return (1);
	}
	write(1, "0", 1);
	return(0);
}
*/
