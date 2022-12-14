/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:18:17 by sde-cama          #+#    #+#             */
/*   Updated: 2022/12/14 10:55:21 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*reset_storage(char *storage, char *tmp_storage);
char	*split_line(char *storage);
char	*ft_read_line(int fd, char *storage);

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*full_str;
	size_t	size_s1;
	size_t	size_s2;
	int		i;

	i = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	full_str = malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (full_str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		full_str[i] = s1[i];
		i++;
	}
	while (s2[i - size_s1] != '\0')
	{
		full_str[i] = s2[i - size_s1];
		i++;
	}
	full_str[i] = '\0';
	return (full_str);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	character;
	unsigned char	*string;

	character = c;
	string = (unsigned char *)s;
	while (*string)
	{
		if (*string == character)
			return ((char *)string);
		string++;
	}
	if (character == '\0')
		return (NULL);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;
	int		i;

	i = 0;
	len = ft_strlen(s) + 1;
	copy = (char *)malloc(sizeof(char) * len);
	if (!copy)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

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
		storage = ft_strjoin2(tmp_storage, current_line);
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

// static char	*read_file(int fd, char *res);
// static char	*ft_line(char *buffer);
// static char	*ft_next(char *buffer);
// static char	*fr_free(char *buffer, char *buf);

// char	*get_next_line(int fd)
// {
// 	static char	*buffer[700];
// 	char		*line;

// 	ft_putstr_fd("> ", 1);
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
// 		return (NULL);
// 	buffer[fd] = read_file(fd, buffer[fd]);
// 	if (!buffer[fd])
// 		return (NULL);
// 	line = ft_line(buffer[fd]);
// 	buffer[fd] = ft_next(buffer[fd]);
// 	return (line);
// }

// static char	*read_file(int fd, char *res)
// {
// 	char	*buffer;
// 	int		byte_read;

// 	if (!res)
// 		res = ft_calloc(1, 1);
// 	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	byte_read = 1;
// 	while (byte_read > 0)
// 	{
// 		byte_read = read(fd, buffer, BUFFER_SIZE);
// 		if (byte_read == -1)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		buffer[byte_read] = 0;
// 		res = fr_free(res, buffer);
// 		if (ft_strchr(buffer, '\n'))
// 			break ;
// 	}
// 	free(buffer);
// 	return (res);
// }

// static char	*ft_line(char *buffer)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	if (!buffer[i])
// 		return (NULL);
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	line = ft_calloc(i + 2, sizeof(char));
// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 	{
// 		line[i] = buffer[i];
// 		i++;
// 	}
// 	if (buffer[i] && buffer[i] == '\n')
// 		line[i++] = '\n';
// 	return (line);
// }

// static char	*ft_next(char *buffer)
// {
// 	int		i;
// 	int		j;
// 	char	*line;

// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	if (!buffer[i])
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
// 	i++;
// 	j = 0;
// 	while (buffer[i])
// 		line[j++] = buffer[i++];
// 	free(buffer);
// 	return (line);
// }

// static char	*fr_free(char *buffer, char *buf)
// {
// 	char	*temp;

// 	temp = ft_strjoin(buffer, buf);
// 	free(buffer);
// 	return (temp);
// }
