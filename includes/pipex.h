/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:23:11 by sde-cama          #+#    #+#             */
/*   Updated: 2022/11/09 11:03:05 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/*to perror*/
# include <stdio.h>

# define FAIL -1
# define SUCCESS 1

# define RED "\x1b[38;5;1m"
# define RESET "\x1b[0m"

typedef enum e_error
{
	ARGUMENT_ERROR,
	INFILE_ERROR,
	OUTFILE_ERROR,
	PIPE_FAIL,
	FORK_FAIL
}	t_error;

typedef struct s_pipex
{
	int	infile;
	int	outfile;
	int	pipe_fd[2];
	char **env;
}	t_pipex;

int	handle_arguments(int argc, char **argv, char **envp, t_pipex *pipex)
int	arg_error(t_error error_type);
int pipex_error(t_error error_type);

#endif
