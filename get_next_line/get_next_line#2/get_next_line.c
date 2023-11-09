/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:20:04 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/09 18:04:44 by mgallais         ###   ########.fr       */
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
	while (!ft_strchr(buf, '\n') && fdres != 0)
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
	char		*reader;
	static char	*keep;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	keep = ft_read_fd(fd, reader);
	if (!keep)
		return (NULL);
//	reader = ft_get_stash(keep);
//	keep = ft_clear_buf(keep);
	return (reader);
}
// debug

int main(void)
{
	char *line = NULL ;
	int fd = 0 ;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (0) ;
		printf("%s" ,line);
		free(line) ;
	}
	return (0);
}
