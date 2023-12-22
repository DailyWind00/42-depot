/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:00:32 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/22 14:04:54 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minitalk.h"

extern char	*g_str;

void	get_int(int signum, int *value)
{
	static int	result = 0;
	static int	i = 0;

	if (signum == SIGUSR2)
		result += 1 << (31 - i);
	i++;
	if (i == 32)
	{
		*value = result;
		result = 0;
		i = 0;
	}
}

void	str_alloc(int str_size, int client_pid)
{
	if (g_str == NULL && str_size > 0)
	{
		g_str = malloc(str_size * sizeof(char));
		if (!g_str)
		{
			kill(client_pid, SIGUSR1);
			free(g_str);
			exit(0);
		}
	}
}

void	next_byte(int *i, int *count, int *c)
{
	if (++(*i) == 8)
	{
		*i = 0;
		g_str[*count] = *c;
		(*count)++;
		*c = 0;
	}
}

void	write_str_reset(int *count, int *i, int *client_pid, int *str_size)
{
	if (*count == *str_size)
	{
		usleep(SLEEP * 2);
		kill(*client_pid, SIGUSR1);
		ft_printf("%s\n", g_str);
		free(g_str);
		*count = 0;
		*i = 0;
		*client_pid = 0;
		*str_size = 0;
	}
}
