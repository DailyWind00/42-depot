/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:09:33 by aallou-v          #+#    #+#             */
/*   Updated: 2023/10/17 19:38:44 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'));
}

/*
int main(int argc, char **argv)
{
	int values = ft_isalpha(76);
	if (values == 1)
	{
		write(1, "1", 1);
		return (1);
	}
	write(1, "0", 1);
	return(0);
}
*/
