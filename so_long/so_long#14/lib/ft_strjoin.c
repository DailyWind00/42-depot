/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aallou-v <aallou-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:53:46 by aallou-v          #+#    #+#             */
/*   Updated: 2023/10/19 01:42:40 by aallou-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;

	if (!s1 || !s2)
		return (NULL);
	r = (char *) ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!r)
		return (NULL);
	ft_strlcpy(r, s1, ft_strlen(s1) + 1);
	ft_strlcat(r, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (r);
}
