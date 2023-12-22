/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:52:49 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/22 14:02:31 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minitalk.h"

char	*g_str = NULL;

static void	handler(int signum)
{
	static int	i = 0;
	static int	client_pid = 0;
	static int	str_size = 0;
	static int	count = 0;
	static int	c = 0;

	if (count == 0 && i == 0)
		g_str = NULL;
	if (client_pid == 0)
		get_int(signum, &client_pid);
	else if (str_size == 0)
		get_int(signum, &str_size);
	else
	{
		str_alloc(str_size, client_pid);
		if (signum == SIGUSR2)
			c += 1 << (7 - i);
		next_byte(&i, &count, &c);
		write_str_reset(&count, &i, &client_pid, &str_size);
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Correct syntax : ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("Server PID : %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (42)
		pause();
	return (0);
}
