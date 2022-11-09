/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:05:18 by sde-cama          #+#    #+#             */
/*   Updated: 2022/11/09 10:56:22 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_commands(char **argv, t_pipex *pipex);

int	handle_arguments(int argc, char **argv, char **envp, t_pipex *pipex)
{
	if (argc != 5)
		return (arg_error(ARGUMENT_ERROR));
	pipex->infile = open(argv[1], O_RDONLY, 0777);
	if (pipex->infile < 0)
		return (arg_error(INFILE_ERROR));
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->outfile < 0)
		return (arg_error(OUTFILE_ERROR));
	if (handle_commands(argv, pipex))
		return (FAIL);
	pipex->env = &envp;
	return (SUCCESS);
}

int	handle_commands(char **argv, t_pipex *pipex)
{
	
}