/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:08:09 by sde-cama          #+#    #+#             */
/*   Updated: 2023/01/06 01:20:17 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_msg(char *msg, int error_code)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(error_code);
}

int	double_error_msg(char *msg, char *name)
{
	ft_putstr_fd(name, STDERR_FILENO);
	write(STDERR_FILENO, ": ", 2);
	ft_putendl_fd(msg, STDERR_FILENO);
	return (-1);
}
