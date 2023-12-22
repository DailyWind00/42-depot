/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:52:49 by mgallais          #+#    #+#             */
/*   Updated: 2023/12/20 16:47:26 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minitalk.h"

static void	writer(int bit)
{
	static unsigned char	c = 0;
	static int				i = 0;

	c |= (bit << i++);
	if (i >= 8)
	{
		if (!c)
			write(1, "\n", 1);
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

static void	handler(int signum)
{
	static int i = 0;

	i++;
	if (signum == SIGUSR1)
		ft_printf("0");
	else if (signum == SIGUSR2)
		ft_printf("1");
	if (i == 32 || (i > 32 && i % 8 == 0))
		ft_printf("\n");
	/*
	static int	i = 0;
	static int	size = 1;
	static char	*str = NULL;

	if (signum == SIGUSR2 && i >= 32);
		size += 1 << (32 - i);
	i++;
	if (!str && i == 32)
		str = ft_calloc(size + 1, sizeof(char));
	if (signum == SIGUSR1 && i < 32)
		writer(0);
	else if (signum == SIGUSR2 && i < 32)
		writer(1);
	if (size == i)
	{
		ft_printf("%d\n", size);
		ft_printf("%s", str);
		free(str);
	}
	*/
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Correct syntax : ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (42)
		pause();
	return (0);
}
