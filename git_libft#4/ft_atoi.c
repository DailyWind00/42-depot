/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:26:26 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/18 15:09:22 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	neg = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && neg == 0)
			neg = -1;
		else if (str[i] == '+' && neg == 0)
			neg = 1;
		else
			return (0);
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result * neg);
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
