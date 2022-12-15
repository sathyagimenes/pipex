// colocar header

#include "pipex.h"

static int		open_file(char *file, int in_or_out);
static void	here_doc(char **av);
static void	here_doc_put_in(char **av, int *p_fd);
static void	do_pipe(char *cmd, char **env);
static void	exec(char *cmd, char **env);

int main(int argc, char **argv, char **envp)
{
	int		i;
	int		fd_in;
	int		fd_out;

	if (argc < 5)
		error_msg("Incorrect arguments. Run in following format: ./pipex_bonus "
				"file_in \"cmd flags\" \"cmd flags\" file_out", 1);	
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0 && ft_strlen(argv[1]) == 8)
	{
		if (argc < 6)
			error_msg("Incorrect arguments. Run in following format: ./pipex_bonus "
				"here_doc limitter \"cmd flags\" \"cmd flags\" file_out", 1);	
		i = 3;
		fd_out = open_file(argv[argc - 1], 2);
		here_doc(argv);
	}
	else
	{
		i = 2;
		fd_in = open_file(argv[1], 0);
		fd_out = open_file(argv[argc - 1], 1);
		dup2(fd_in, 0);
	}
	if (fd_in < 0 || fd_out < 0)
		exit(0);
	while (i < argc - 2)
		do_pipe(argv[i++], envp);
	dup2(fd_out, 1);
	exec(argv[argc - 2], envp);
	return(0);
}

static int open_file(char *file, int in_or_out)
{
	int ret;

	if (in_or_out == 0)
		ret = open(file, O_RDONLY);
	if (in_or_out == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (in_or_out == 2)
		ret = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (ret < 0)
		return (double_error_msg(strerror(errno), file));
	return (ret);
}

static void here_doc(char **av)
{
	int p_fd[2];
	pid_t pid;

	if (pipe(p_fd) == -1)
		error_msg("Pipe fail. Could not pipe files.", 1);
	pid = fork();
	if (pid == -1)
		error_msg("Fork fail. Could not fork.", 1);
	if (!pid)
		here_doc_put_in(av, p_fd);
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		wait(NULL);
	}
}

static void here_doc_put_in(char **av, int *p_fd)
{
	char *ret;

	close(p_fd[0]);
	while (1)
	{
		ret = get_next_line(0, av[2]);
		if (ft_strncmp(ret, av[2], ft_strlen(av[2])) == 0)
		{
			free(ret);
			exit(0);
		}
		ft_putstr_fd(ret, p_fd[1]);
		free(ret);
	}
}

static void do_pipe(char *cmd, char **env)
{
	pid_t pid;
	int p_fd[2];

	if (pipe(p_fd) == -1)
		error_msg("Pipe fail. Could not pipe files.", 1);
	pid = fork();
	if (pid == -1)
		error_msg("Fork fail. Could not fork.", 1);
	if (!pid)
	{
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		exec(cmd, env);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
	}
}

static void exec(char *cmd, char **env)
{
	char **s_cmd;
	char *path;

	if (ft_strnstr(cmd, " ' '", ft_strlen(cmd)))
		cmd = swap_space_arg(cmd, " ' '", " 0x0");
	s_cmd = ft_split(cmd, ' ');
	if (s_cmd == NULL)
		error_msg(strerror(errno), 1);
	s_cmd = replace_in_matriz(s_cmd, "0x0", "  ");
	path = find_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		double_error_msg("comando não encontrado", s_cmd[0]);
		free_mem(s_cmd);
		exit(127);
	}
}
