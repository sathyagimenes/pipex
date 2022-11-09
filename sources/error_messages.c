/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:08:09 by sde-cama          #+#    #+#             */
/*   Updated: 2022/11/09 10:20:19 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int arg_error(t_error error_type)
{
	char *message;
	char *valid_example;

	message = "Undefined";
	if (error_type == ARGUMENT_ERROR)
		message = "Invalid quantity of arguments.\n";
	else if (error_type == INFILE_ERROR)
		message = "Invalid infile. Could not open infile.\n";
	else if (error_type == OUTFILE_ERROR)
		message = "Invalid outfile. Could not open or create outfile.\n";
	valid_example = "Valid example: ./pipex infile \"ls -l\" \"wc -l\" outfile\n";
	ft_printf(RED "Error\n%s%s" RESET, message, valid_example);
	return (FAIL);
}

int pipex_error(t_error error_type)
{
	char *message;

	message = "Undefined";
	if (error_type == PIPE_FAIL)
		message = "Pipe fail. Could not pipe files.\n";
	else if (error_type == FORK_FAIL)
		message = "Fork fail. Could not fork.\n";
	ft_printf(RED "Error\n%s" RESET, message);
	return (FAIL);
}