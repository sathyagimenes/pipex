/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:08:09 by sde-cama          #+#    #+#             */
/*   Updated: 2022/12/14 08:21:04 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int cmd_error(char *cmd)
{
	write(STDERR_FILENO, cmd, ft_strlen(cmd));
	write(STDERR_FILENO, ": comando não encontrado\n", 27);
	return (0);
}

int error_msg(char *msg, int error_code)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(error_code);
}

int double_error_msg(char *msg, char *name)
{
	ft_putstr_fd(name, STDERR_FILENO);
	write(STDERR_FILENO, ": ", 2);
	ft_putendl_fd(msg, STDERR_FILENO);
	return (0);
}
