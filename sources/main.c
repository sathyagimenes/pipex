/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:21:12 by sde-cama          #+#    #+#             */
/*   Updated: 2022/12/10 11:36:22 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void child_execution(char **argv, char **envp, t_pipex *pipex);
void parent_execution(char **argv, char **envp, t_pipex *pipex);
void exec_command(char *cmd, char **envp);
char *find_path(char *cmd, char **env);
char *swap_space_arg(char *command, char *what_change, char *to_swap);
char **replace_in_matriz(char **matriz, char *what_change, char *to_swap);
void free_mem(char **mem);

int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;
	int status;
	int pid;

	if (!handle_arguments(argc, argv, &pipex))
		exit(0);
	if (pipe(pipex.pipe_fd) == -1)
		error_msg("Pipe fail. Could not pipe files.", 1);
	pid = fork();
	if (pid == -1)
		error_msg("Fork fail. Could not fork.", 1);
	if (pid == 0)
		child_execution(argv, envp, &pipex);
	if (pid != 0)
	{
		waitpid(pid, &status, WNOHANG);
		if (WEXITSTATUS(status) == 127)
			error_msg(strerror(errno), 127);
		parent_execution(argv, envp, &pipex);
	}
	return (0);
}

void child_execution(char **argv, char **envp, t_pipex *pipex)
{
	dup2(pipex->infile, 0);
	dup2(pipex->pipe_fd[1], 1);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	close(pipex->infile);
	close(pipex->outfile);
	exec_command(argv[2], envp);
}

void parent_execution(char **argv, char **envp, t_pipex *pipex)
{
	dup2(pipex->outfile, 1);
	dup2(pipex->pipe_fd[0], 0);
	close(pipex->pipe_fd[1]);
	close(pipex->pipe_fd[0]);
	close(pipex->infile);
	close(pipex->outfile);
	exec_command(argv[3], envp);
}

void exec_command(char *cmd, char **envp)
{
	char **cmd_args;
	char *path;

	if (ft_strnstr(cmd, " ' '", ft_strlen(cmd)))
		cmd = swap_space_arg(cmd, " ' '", " 0x0");
	cmd_args = ft_split(cmd, ' ');
	if (cmd_args == NULL)
		error_msg(strerror(errno), 1);
	cmd_args = replace_in_matriz(cmd_args, "0x0", "  ");
	path = find_path(cmd_args[0], envp);
	if (execve(path, cmd_args, envp) == -1)
	{
		double_error_msg("comando não encontrado", cmd_args[0]);
		free_mem(cmd_args);
		exit(127);
	}
}

char *find_path(char *cmd, char **env)
{
	char *env_path;
	char **paths;
	char *cmd_line;
	char *full_path;
	int i;

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
				free_mem(paths);
				return (cmd_line);
			}
			free(cmd_line);
			i++;
		}
	}
	free_mem(paths);
	return (cmd);
}

void free_mem(char **mem)
{
	int i;

	i = 0;
	while (mem[i])
	{
		free(mem[i]);
		i++;
	}
	free(mem);
}

char *swap_space_arg(char *command, char *what_change, char *to_swap) // rever isso
{
	int c;
	int w;
	int aux;

	c = 0;
	w = 0;
	aux = 0;
	while (command[c] != '\0')
	{
		while (command[c + w] == what_change[w])
		{
			command[c + w] = to_swap[aux];
			w++;
			aux++;
		}
		c++;
	}
	return (command);
}

char **replace_in_matriz(char **matriz, char *what_change, char *to_swap) // rever isso
{
	int i;

	i = 1;
	while (matriz[i])
	{
		if (ft_strnstr(matriz[i], what_change, ft_strlen(matriz[i])))
		{
			free(matriz[i]);
			matriz[i] = ft_strdup(to_swap);
		}
		i++;
	}
	return (matriz);
}
