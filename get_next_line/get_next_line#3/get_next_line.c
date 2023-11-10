/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:20:04 by mgallais          #+#    #+#             */
/*   Updated: 2023/11/10 11:48:11 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extract_line(char *stash)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i);
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, i);
	free(stash);
	return (line);
}

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
	free(buf2);
	return (buf);
}

static char	*ft_clean_stash(char *stash)
{
	char	*new_stash;

	new_stash = ft_strchr(stash, '\n');
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	return (new_stash + 1);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;

	buf = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_fd(fd, stash);
	if (!stash)
		return (NULL);
	buf = ft_extract_line(stash);
	stash = ft_clean_stash(stash);
	return (buf);
}
// debug
/*
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
*/
