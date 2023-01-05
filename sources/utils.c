// colocar header

#include "pipex.h"

char *tokenization(char *cmd, t_token *token);
void revert_token(t_token *token);

char **split_cmd(char *cmd)
{
	t_token token;

	cmd = tokenization(cmd, &token);
	token.splited_cmd = ft_split(cmd, ' ');
	if (token.splited_cmd == NULL)
		error_msg(strerror(errno), 1);
	revert_token(&token);
	free_mem(token.flags);
	return (token.cmd_parsed);
}

char *tokenization(char *cmd, t_token *token)
{
	token->i = 0;
	token->k = 0;
	token->flags = ft_calloc(sizeof(char *), 5);
	while (cmd[token->k])
	{
		if (cmd[token->k] == '\'')
		{
			token->j = 0;
			token->k++;
			while (cmd[token->k + token->j] != '\'' && cmd[token->k + token->j])
			{
				if (token->j == 0)
					token->flags[token->i] = ft_calloc(sizeof(char), 20);
				token->flags[token->i][token->j] = cmd[token->k + token->j];
				cmd[token->k + token->j] = 'x';
				token->j++;
			}
			token->i++;
			token->k += token->j;
		}
		token->k++;
	}
	token->flags[token->i] = '\0';
	return (cmd);
}

void revert_token(t_token *token)
{
	token->i = 0;
	token->k = 0;
	token->cmd_parsed = ft_calloc(sizeof(char *), 5);
	while (token->splited_cmd[token->i])
	{
		if (token->splited_cmd[token->i][0] == '\'')
		{
			token->cmd_parsed[token->i] = ft_calloc(ft_strlen(token->splited_cmd[token->i]), sizeof(char));
			token->j = 1;
			while (token->splited_cmd[token->i][token->j] == 'x')
			{
				token->cmd_parsed[token->i][token->j - 1] = token->flags[token->k][token->j - 1];
				token->j++;
				if (token->splited_cmd[token->i][token->j] == '\'')
					token->k++;
			}
			if (token->cmd_parsed[token->i][1] == '{' && token->cmd_parsed[token->i][token->j - 1] == '}')
			{
				token->cmd_parsed[token->i][0] = ' ';
				token->cmd_parsed[token->i][token->j] = ' ';
			}
		}
		else
			token->cmd_parsed[token->i] = ft_strdup(token->splited_cmd[token->i]);
		token->i++;
	}
	free_mem(token->splited_cmd);
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
