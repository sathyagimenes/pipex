/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:23:11 by sde-cama          #+#    #+#             */
/*   Updated: 2023/01/06 01:13:14 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>

# include <errno.h>

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

typedef enum e_error
{
	ARGUMENT_ERROR,
	INFILE_ERROR,
	OUTFILE_ERROR,
	PIPE_FAIL,
	FORK_FAIL,
	CMD_FAIL
}	t_error;

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipe_fd[2];
	char	**env;
	char	**cmd;
	char	*limiter;
}	t_pipex;

typedef struct s_token
{
	char	**flags;
	char	**undo_t;
	char	**splited_cmd;
	int		i;
	int		j;
	int		k;
}	t_token;

int		main(int argc, char **argv, char **envp);
int		handle_arguments(int argc, char **argv, t_pipex *pipex);
int		cmd_error(char *cmd);
int		error_msg(char *msg, int error_code);
int		double_error_msg(char *msg, char *name);
char	*find_path(char *cmd, char **env);
char	**split_cmd(char *cmd);
void	free_mem(char **mem);
char	*find_path(char *cmd, char **env);
char	*get_next_line(int fd, char *limitter);

#endif
