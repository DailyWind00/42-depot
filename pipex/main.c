/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:54:00 by mgallais          #+#    #+#             */
/*   Updated: 2024/01/30 09:38:45 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*ft_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strncmp(sub, name, 1000) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

static char	*get_path(char *cmd, char **env)
{
	t_path	path;

	path.i = -1;
	path.allpath = ft_split(ft_getenv("PATH", env), ':');
	path.s_cmd = ft_split(cmd, ' ');
	while (path.allpath[++path.i])
	{
		path.path_part = ft_strjoin(path.allpath[path.i], "/");
		path.exec = ft_strjoin(path.path_part, path.s_cmd[0]);
		free(path.path_part);
		if (access(path.exec, F_OK | X_OK) == 0)
		{
			while (path.s_cmd[path.j])
				free(path.s_cmd[path.j++]);
			return (path.exec);
		}
		free(path.exec);
	}
	while (path.allpath[path.j])
		free(path.allpath[path.j++]);
	path.j = 0;
	while (path.s_cmd[path.j])
		free(path.s_cmd[path.j++]);
	return (cmd);
}

static void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;
	int		i;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_printf("Command not found : %s", s_cmd[0]);
		i = 0;
		while (s_cmd[i])
			free(s_cmd[i++]);
		exit(0);
	}
}

static void	pipex(char **argv, int *pipefd, char **env, int pid)
{
	int	fd;

	if (pid)
	{
		fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
			exit(0);
		dup2(fd, 1);
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		exec(argv[3], env);
		return ;
	}
	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		exit(0);
	dup2(fd, 0);
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	exec(argv[2], env);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_printf("Correct usage : ./pipex infile cmd cmd outfile\n");
		exit(0);
	}
	if (pipe(pipefd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	pipex(argv, pipefd, env, pid);
}
