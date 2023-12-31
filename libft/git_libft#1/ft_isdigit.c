/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:54:09 by mgallais          #+#    #+#             */
/*   Updated: 2023/10/17 14:54:22 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int C)
{
	if (C >= '0' && C <= '9')
		return (1);
	return (0);
}
