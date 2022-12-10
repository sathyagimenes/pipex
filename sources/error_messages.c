/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:08:09 by sde-cama          #+#    #+#             */
/*   Updated: 2022/12/09 11:36:22 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void arg_error(t_error error_type, int error_code)
{
	char *message;

	message = "Undefined\n";
	if (error_type == ARGUMENT_ERROR)
		message = "Incorrect arguments. Run in following format: ./pipex "
				  "file_in \"cmd flags\" \"cmd flags\" file_out";
	else if (error_type == INFILE_ERROR)
		message = "Invalid infile. Could not open infile.\n";
	else if (error_type == OUTFILE_ERROR)
		message = "Invalid outfile. Could not open or create outfile.\n";
	ft_putendl_fd(message, STDERR_FILENO);
	exit(error_code);
}

int pipex_error(t_error error_type)
{
	if (error_type == PIPE_FAIL)
		perror("Pipe fail. Could not pipe files.\n");
	else if (error_type == FORK_FAIL)
		perror("Fork fail. Could not fork.\n");
	return (0);
}

int cmd_error(t_error error_type, char *cmd)
{
	if (error_type == CMD_FAIL)
	{
		write(2, cmd, ft_strlen(cmd));
		write(2, ": comando não encontrado\n", 27);
	}
	else
	{
		perror("Could not execute cmd\n");
	}
	return (0);
}

void exit_msg(char *msg, int error_code)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(error_code);
}

int error_msg(char *msg, int error_code)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	return (error_code);
}

int double_error_msg(char *msg, char *name, int error_code)
{
	ft_putstr_fd(name, STDERR_FILENO);
	write(2, ": ", 2);
	ft_putendl_fd(msg, STDERR_FILENO);
	return (error_code);
}