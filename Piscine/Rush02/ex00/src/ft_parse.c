/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 10:32:25 by mgallais          #+#    #+#             */
/*   Updated: 2023/07/23 10:33:13 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_itoal.h"

void	read_lines(int fd, char **lines)
{
	char	c;
	int		i;
	int		j;
	char	*cur_string;

	i = 0;
	j = 0;
	cur_string = (char *)malloc(sizeof(char) * 50);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
		{
			lines[j] = ft_strdup(cur_string);
			free(cur_string);
			cur_string = (char *)malloc(sizeof(char) * 50);
			i = 0;
			j++;
		}
		cur_string[i++] = c;
	}
	lines[j] = NULL;
}

int	count_lines(int fd)
{
	int		count;
	char	c;

	count = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			count++;
	}
	return (count);
}

char	*str_from_alpha(char **lines, long nb)
{
	int		i;
	int		j;
	int		k;
	char	cur_nb[50];
	char	*ref;

	i = -1;
	j = 0;
	while (lines[++i])
	{
		k = 0;
		while (lines[i][j] && (lines[i][j] != ':' && lines[i][j] != ' '))
			cur_nb[k++] = lines[i][j++];
		cur_nb[k] = '\0';
		while (lines[i][j] && (lines[i][j] == ':' || lines[i][j] == ' '))
			j++;
		ref = ft_strdup(&lines[i][j]);
		if (ft_atol(cur_nb) == nb)
			return (ref);
		j = 0;
		cur_nb[0] = '\0';
	}
	return (ft_strdup("Error"));
}

char	*ft_proccess_number(long number, char **lines, char **av)
{
	char	*reference;

	if (ft_strlen(av[1]) == 1 || ft_strlen(av[1]) == 2)
		reference = str_from_alpha(lines, number);
	else if (ft_strlen(av[1]) % 3 == 0)
	{
		reference = str_from_alpha(lines, number / 100);
		ft_strcat(reference, " hundred");
	}
	else if (ft_strlen(av[1]) >= 4 && ft_strlen(av[1]) <= 6)
	{
		reference = str_from_alpha(lines, number / 1000);
		ft_strcat(reference, " thousand");
	}
	else
	{
		reference = ft_we_love_norme(number, lines, av);
	}
	return (reference);
}

char	**get_lines(char *path)
{
	int		line_count;
	int		fd;
	char	**lines;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line_count = count_lines(fd);
	close(fd);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	lines = (char **)malloc(sizeof(char *) * (line_count + 1));
	read_lines(fd, lines);
	close(fd);
	return (lines);
}
