/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:05:18 by sde-cama          #+#    #+#             */
/*   Updated: 2022/12/10 15:50:17 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_arguments(int argc, char **argv, t_pipex *pipex)
{
	if (argc != 5)
		error_msg("Incorrect arguments. Run in following format: ./pipex "
			"file_in \"cmd flags\" \"cmd flags\" file_out", 1);
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->infile < 0)
		return (double_error_msg(strerror(errno), argv[1]));
	if (pipex->outfile < 0)
		return (double_error_msg(strerror(errno), argv[4]));
	return (1);
}
