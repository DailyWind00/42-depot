/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:50:17 by aallou-v          #+#    #+#             */
/*   Updated: 2023/10/19 16:27:48 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_occurrence = (char *)s;
		s++;
	}
	if (*s == (const char) c)
		return ((char *) s);
	return (last_occurrence);
}

/*
int	main(int argc, char **agrv)
{
	char	*v1 = "teste";
	char	*v2 = ft_strrchr(v1, '\0');
	printf("%s / %s", v1, v2);
	return (1);
}
*/
