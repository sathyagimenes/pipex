/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:08:09 by sde-cama          #+#    #+#             */
/*   Updated: 2022/11/13 21:26:28 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int arg_error(t_error error_type)
{
	char *message;
	char *valid_example;

	message = "Undefined\n";
	if (error_type == ARGUMENT_ERROR)
		message = "Invalid quantity of arguments.\n";
	else if (error_type == INFILE_ERROR)
		message = "Invalid infile. Could not open infile.\n";
	else if (error_type == OUTFILE_ERROR)
		message = "Invalid outfile. Could not open or create outfile.\n";
	valid_example = "Valid example: ./pipex infile \"ls -l\" \"wc -l\" outfile\n";
	ft_printf(RED "Error\n%s%s" RESET, message, valid_example);
	return (0);
}

int pipex_error(t_error error_type)
{
	if (error_type == PIPE_FAIL)
		perror(RED "Pipe fail. Could not pipe files.\n" RESET);
	else if (error_type == FORK_FAIL)
		perror(RED "Fork fail. Could not fork.\n" RESET);
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
		perror(RED "Could not execute cmd\n" RESET);
	}
	return (0);
}
