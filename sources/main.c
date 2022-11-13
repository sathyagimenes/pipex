/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:21:12 by sde-cama          #+#    #+#             */
/*   Updated: 2022/11/13 12:18:40 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_execution(char **argv, char **envp, t_pipex *pipex);
void	parent_execution(char **argv, char **envp, t_pipex *pipex);
void	exec_command(char *cmd, char **envp);
char	*find_path(char *cmd, char **env);

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		pid;

	if (!handle_arguments(argc, argv, &pipex))
		exit(FAIL);
	if (pipe(pipex.pipe_fd) == -1)
	{
		pipex_error(PIPE_FAIL);
		exit(FAIL);
	}
	pid = fork();
	if (pid == -1)
	{
		pipex_error(FORK_FAIL);
		exit(FAIL);
	}
	if (pid == 0)
		child_execution(argv, envp, &pipex);
	parent_execution(argv, envp, &pipex);
	return (SUCCESS);
}

void	child_execution(char **argv, char **envp, t_pipex *pipex)
{
	close(pipex->pipe_fd[0]);
	dup2(pipex->infile, 0);
	dup2(pipex->pipe_fd[1], 1);
	exec_command(argv[2], envp);
}

void	parent_execution(char **argv, char **envp, t_pipex *pipex)
{
	close(pipex->pipe_fd[1]);
	dup2(pipex->outfile, 1);
	dup2(pipex->pipe_fd[0], 0);
	exec_command(argv[3], envp);
}

void	exec_command(char *cmd, char **envp)
{
	char	**cmd_args;
	char	*path;

	cmd_args = ft_split(cmd, ' ');
	path = find_path(cmd_args[0], envp);
	if (execve(path, cmd_args, envp) == -1)
	{
		free(cmd_args);
		free(path);
		cmd_error(CMD_FAIL, cmd_args[0]);
		exit(FAIL);
	}
}

char	*find_path(char *cmd, char **env) //talvez tenha que dar algumas adaptadas
{
	char	*env_path;
	char	**paths;
	char	*cmd_line;
	char	*full_path;
	int		i;

	if (cmd[0] == '/' || cmd[0] == '.')
		return (cmd);
	else
	{
		i = 0;
		while (env[i] && !ft_strnstr(env[i], "PATH=", 5))
			i++;
		if (!env[i])
			return (cmd);
		env_path = env[i] + 6;
		paths = ft_split(env_path, ':');
		i = 0;
		while (paths[i])
		{
			full_path = ft_strjoin(paths[i], "/");
			cmd_line = ft_strjoin(full_path, cmd);
			free(full_path);
			if (access(cmd_line, F_OK) == 0)
			{
				free(paths);
				return (cmd_line);
			}
			free(cmd_line);
			i++;
		}
	}
	free(paths);
	return (cmd);
}
