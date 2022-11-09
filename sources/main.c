/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:21:12 by sde-cama          #+#    #+#             */
/*   Updated: 2022/11/09 11:07:43 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		pid;

	if (!handle_arguments(argc, argv, envp, &pipex))
		exit(FAIL);
	if (pipe(pipex.pipe_fd) == -1)
		return (pipex_error(PIPE_FAIL));
	pid = fork();
	if (pid == -1)
		return (pipex_error(FORK_FAIL));
	if (pid == 0)
		child_execution(&pipex);
	parent_execution(&pipex);
	return (SUCCESS);
}

void	child_execution(t_pipex *pipex)
{
	close(pipex->pipe_fd[0]);
	dup2(pipex->infile, 0);
	dup2(pipex->pipe_fd[1], 1);
	//executing part
}

void	parent_execution(t_pipex *pipex)
{
	close(pipex->pipe_fd[1]);
	dup2(pipex->outfile, 1);
	dup2(pipex->pipe_fd[0], 0);
	//executing part
}
