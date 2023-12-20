/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:51:21 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/20 16:48:56 by mgallais         ###   ########.fr       */
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

static void	send_size(unsigned int size, pid_t pid)
{
	int	i;

	i = 31;
	ft_printf("Size = ");
	while (i >= 0)
	{
		if ((size >> i) & 1)
		{
			ft_printf("1");
			kill(pid, SIGUSR2);
		}
		else
		{
			ft_printf("0");
			kill(pid, SIGUSR1);
		}
		i--;
		usleep(SLEEP);
	}
	ft_printf("\n");
}

static void	send_char(char c, pid_t pid)
{
	int	i;

	i = 7;
	ft_printf("Letter = ");
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			ft_printf("1");
			kill(pid, SIGUSR2);
		}
		else
		{
			ft_printf("0");
			kill(pid, SIGUSR1);
		}
		i--;
		usleep(SLEEP);
	}
	ft_printf("\n");
}

void	send_str(const char *str, pid_t pid)
{
	while (*str)
	{
		send_char(*str, pid);
		str++;
	}
	send_char('\0', pid);
}

int	main(int argc, char **argv)
{
	unsigned int	size;
	pid_t			pid;

	size = check_argument(argc, argv);
	if (size)
	{
		pid = ft_atoi(argv[1]);
		send_size(size, pid);
		send_str(argv[2], pid);
	}
	else
		ft_printf("Correct syntax : ./client <SERVER_PID> <TEXT>\n");
	return (0);
}
