/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:26:26 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/19 09:24:28 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	neg;

	i = 0;
	nb = 0;
	neg = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10;
		nb = nb + str[i] - 48;
		i++;
	}
	if (neg == 1)
		return (-nb);
	return (nb);
}
//debug
/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[20];  // Input string representing an integer
    int num;

    printf("Enter an integer as a string: ");
    scanf("%s", str);

    num = ft_atoi(str);
    printf("The integer value is: %d\n", num);
    num = atoi(str);
    printf("The integer value is: %d\n", num);
    return 0;
}
*/
