// colocar header

#include "pipex.h"

char **split_cmd(char *cmd)
{
	// char	*new_cmd;
	char **flags;
	char **cmd_parsed;
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	// flags = ft_calloc();
	flags = ft_calloc(sizeof(char *), 5);
	while (cmd[k])
	{
		// new_cmd = ft_strnstr(cmd, "'", ft_strlen(cmd));
		if (cmd[k] == '\'') // adicionar para aspas duplas tbm"
		{
			j = 0;
			k++;
			while (cmd[k + j] != '\'' && cmd[k + j])
			{
				if (j == 0)
					flags[i] = ft_calloc(sizeof(char), 10); // alterar tamanho
				flags[i][j] = cmd[k + j];
				cmd[k + j] = 'x';
				j++;
			}
			if (cmd[k + j] != '\'')
				ft_printf("missing end of quoting");
			i++;
			k += j;
		}
		k++;
	}
	flags[i] = '\0';
	i = 0;
	k = 0;
	cmd_parsed = ft_split(cmd, ' ');
	while (cmd_parsed[i])
	{
		if (cmd_parsed[i][0] == '\'')
		{
			j = 1;
			while (cmd_parsed[i][j] == 'x')
			{
				cmd_parsed[i][j] = flags[k][j - 1];
				j++;
				if (cmd_parsed[i][j] == '\'')
					k++;
			}
			if (cmd_parsed[i][1] == '{' && cmd_parsed[i][j - 1] == '}')
			{
				cmd_parsed[i][0] = ' ';
				cmd_parsed[i][j] = ' ';
			}
		}
		i++;
	}
	return (cmd_parsed);
}

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

// char *swap_space_arg(char *command, char *what_change, char *to_swap)
// {
// 	int c;
// 	int w;
// 	int aux;

// 	c = 0;
// 	w = 0;
// 	aux = 0;
// 	while (command[c] != '\0')
// 	{
// 		while (command[c + w] == what_change[w])
// 		{
// 			command[c + w] = to_swap[aux];
// 			w++;
// 			aux++;
// 		}
// 		c++;
// 	}
// 	return (command);
// }

// char **replace_in_matriz(char **matriz, char *what_change, char *to_swap)
// {
// 	int i;

// 	i = 1;
// 	while (matriz[i])
// 	{
// 		if (ft_strnstr(matriz[i], what_change, ft_strlen(matriz[i])))
// 		{
// 			free(matriz[i]);
// 			matriz[i] = ft_strdup(to_swap);
// 		}
// 		i++;
// 	}
// 	return (matriz);
// }

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
