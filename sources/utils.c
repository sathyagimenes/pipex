//colocar header

#include "pipex.h"

char *find_path(char *cmd, char **env)
{
	char *env_path;
	char **paths;
	char *cmd_line;
	char *full_path;
	int i;

	if (cmd[0] == '/' || cmd[0] == '.')
		return (cmd);
	else
	{
		i = 0;
		while (env[i] && !ft_strnstr(env[i], "PATH=", 5))
			i++;
		if (!env[i])
			return (cmd);
		env_path = env[i] + 6;
		paths = ft_split(env_path, ':');
		i = 0;
		while (paths[i])
		{
			full_path = ft_strjoin(paths[i], "/");
			cmd_line = ft_strjoin(full_path, cmd);
			free(full_path);
			if (access(cmd_line, F_OK) == 0)
			{
				free_mem(paths);
				return (cmd_line);
			}
			free(cmd_line);
			i++;
		}
	}
	free_mem(paths);
	return (cmd);
}

char *swap_space_arg(char *command, char *what_change, char *to_swap) // rever isso
{
	int c;
	int w;
	int aux;

	c = 0;
	w = 0;
	aux = 0;
	while (command[c] != '\0')
	{
		while (command[c + w] == what_change[w])
		{
			command[c + w] = to_swap[aux];
			w++;
			aux++;
		}
		c++;
	}
	return (command);
}

char **replace_in_matriz(char **matriz, char *what_change, char *to_swap) // rever isso
{
	int i;

	i = 1;
	while (matriz[i])
	{
		if (ft_strnstr(matriz[i], what_change, ft_strlen(matriz[i])))
		{
			free(matriz[i]);
			matriz[i] = ft_strdup(to_swap);
		}
		i++;
	}
	return (matriz);
}

void free_mem(char **mem)
{
	int i;

	i = 0;
	while (mem[i])
	{
		free(mem[i]);
		i++;
	}
	free(mem);
}
