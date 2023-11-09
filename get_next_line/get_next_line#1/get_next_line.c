/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:20:04 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/09 15:23:19 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_fd(int fd, char *buf)
{
	char	*buf2;
	int		fdres;

	buf2 = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	fdres = 1;
	if (!buf2)
		return (NULL);
	while (!strchr(buf, '\n') && fdres != 0)
	{
		fdres = read(fd, buf2, BUFFER_SIZE);
		if (fdres == -1)
		{
			free(buf2);
			return (NULL);
		}
		buf2[fdres] = 0; 
		buf = ft_strjoin(buf, buf2);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*stash;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_read_fd(fd, stash);
	if (!buf)
		return (NULL);
	stash = ft_get_stash(buf);
	buf = ft_clear_buf(buf);
	return (stash);
}
