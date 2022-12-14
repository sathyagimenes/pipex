/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:18:17 by sde-cama          #+#    #+#             */
/*   Updated: 2022/12/14 11:24:17 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*reset_storage(char *storage, char *tmp_storage);
char	*split_line(char *storage);
char	*ft_read_line(int fd, char *storage);

char	*get_next_line(int fd, char *limitter)
{
	static char	*storage;
	char		*current_line;
	char		*temp_storage;

	ft_putstr_fd("> ", 1);
	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	if (storage == NULL)
		temp_storage = ft_strdup("");
	else
		temp_storage = ft_strdup(storage);
	temp_storage = ft_read_line(fd, temp_storage);
	if (temp_storage == NULL)
	{
		free(temp_storage);
		free(storage);
		storage = NULL;
		return (NULL);
	}
	current_line = split_line(temp_storage);
	storage = reset_storage(storage, temp_storage);
	if (ft_strncmp(current_line, limitter, ft_strlen(limitter)) == 0)
	{
		free(storage);
	}
	free(temp_storage);
	return (current_line);
}

char	*ft_read_line(int fd, char *storage)
{
	char	*current_line;
	int		bytes_read;
	char	*tmp_storage;

	current_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!current_line)
		return (NULL);
	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && (ft_strchr(storage, '\n') == NULL))
	{
		bytes_read = read(fd, current_line, BUFFER_SIZE);
		if (bytes_read < 0 || (bytes_read == 0 && storage[0] == '\0'))
		{
			free(current_line);
			free(storage);
			return (NULL);
		}
		current_line[bytes_read] = '\0';
		tmp_storage = storage;
		storage = ft_strjoin(tmp_storage, current_line);
		free(tmp_storage);
	}
	free(current_line);
	return (storage);
}

char	*split_line(char *storage)
{
	int		count;
	int		i;
	char	*new_line;

	count = 0;
	while (storage[count] != '\n' && storage[count] != '\0')
		count++;
	if (storage[count] == '\n')
		count++;
	new_line = malloc((count * sizeof(char)) + 1);
	i = 0;
	while (i < count)
	{
		new_line[i] = storage[i];
		i++;
	}
	new_line[count] = '\0';
	return (new_line);
}

char	*reset_storage(char *storage, char *tmp_storage)
{
	free(storage);
	storage = ft_strchr(tmp_storage, '\n');
	if (storage != NULL)
		storage = ft_strdup(storage + 1);
	return (storage);
}
