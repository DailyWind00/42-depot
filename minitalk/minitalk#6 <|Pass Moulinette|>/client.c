/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:51:21 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/22 15:05:42 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minitalk.h"

static int	check_argument(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (!ft_isdigit(argv[1][i]))
				return (0);
			i++;
		}
		i = 0;
		while (argv[2][i])
			i++;
		return (i + 1);
	}
	return (0);
}

static void	send_int(unsigned int size, pid_t pid)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if ((size >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(SLEEP);
	}
}

static void	send_str(const char *str, pid_t pid)
{
	int	i;

	i = 42;
	while (*(str - 1) || i == 42)
	{
		i = 7;
		while (i >= 0)
		{
			if ((*str >> i) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i--;
			usleep(SLEEP);
		}
		str++;
	}
}

static void	client_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf(" ---> Successfully wrote on the server, Yippiiiie !!!\n");
	else if (signum == SIGUSR2)
		ft_printf(" ---> Error : Server closed\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	unsigned int	size;
	pid_t			pid;

	size = check_argument(argc, argv);
	if (size)
	{
		pid = ft_atoi(argv[1]);
		send_int(getpid(), pid);
		send_int(size, pid);
		send_str(argv[2], pid);
		signal(SIGUSR1, client_handler);
		signal(SIGUSR2, client_handler);
		ft_printf("\n[BONUS] Waiting for server response...\n");
		while (42)
			pause();
	}
	else
		ft_printf("Correct syntax : ./client <SERVER_PID> <TEXT>\n");
	return (0);
}
