/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:21:12 by sde-cama          #+#    #+#             */
/*   Updated: 2023/01/04 21:07:41 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void child_execution(char *cmd, char **envp, t_pipex *pipex);
static void parent_execution(char *cmd, char **envp, t_pipex *pipex);
static void exec_command(char *cmd, char **envp);

int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;
	int status;
	int pid;

	if (handle_arguments(argc, argv, &pipex) < 0)
		exit(0);
	if (pipe(pipex.pipe_fd) == -1)
		error_msg("Pipe fail. Could not pipe files.", 1);
	pid = fork();
	if (pid == -1)
		error_msg("Fork fail. Could not fork.", 1);
	if (pid == 0)
		child_execution(argv[2], envp, &pipex);
	if (pid != 0)
	{
		waitpid(pid, &status, WNOHANG);
		if (WEXITSTATUS(status) == 127)
			error_msg(strerror(errno), 127);
		parent_execution(argv[3], envp, &pipex);
	}
	return (0);
}

static void child_execution(char *cmd, char **envp, t_pipex *pipex)
{
	dup2(pipex->infile, 0);
	dup2(pipex->pipe_fd[1], 1);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	close(pipex->infile);
	close(pipex->outfile);
	exec_command(cmd, envp);
}

static void parent_execution(char *cmd, char **envp, t_pipex *pipex)
{
	dup2(pipex->outfile, 1);
	dup2(pipex->pipe_fd[0], 0);
	close(pipex->pipe_fd[1]);
	close(pipex->pipe_fd[0]);
	close(pipex->infile);
	close(pipex->outfile);
	exec_command(cmd, envp);
}

static void exec_command(char *cmd, char **envp)
{
	char **cmd_args;
	char *path;

	cmd_args = split_cmd(cmd);
	path = find_path(cmd_args[0], envp);
	if (execve(path, cmd_args, envp) == -1)
	{
		double_error_msg("comando não encontrado", cmd_args[0]);
		free_mem(cmd_args);
		exit(127);
	}
}
