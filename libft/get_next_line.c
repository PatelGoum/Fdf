/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguerin <maguerin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:08:04 by maguerin          #+#    #+#             */
/*   Updated: 2024/08/23 18:02:26 by maguerin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*result;
	static char	*line;

	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) < 0)
		return (free(line), line = NULL, NULL);
	if (!line)
	{
		line = ft_calloc(1, sizeof(char));
		if (!line)
			return (free(line), line = NULL, NULL);
	}
	line = line_builder(fd, line);
	if (!line)
		return (free(line), line = NULL, NULL);
	result = ft_get_line(line);
	if (!result)
		return (free(result), free(line), line = NULL, NULL);
	line = line_remainder(line);
	if (!line)
		return (free(result), free(line), line = NULL, NULL);
	return (result);
}

char	*line_builder(int fd, char *line)
{
	char	*buffer;
	int		byteread;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(buffer), NULL);
	byteread = 1;
	while (!ft_strchr(line, '\n') && byteread != 0)
	{
		byteread = read(fd, buffer, BUFFER_SIZE);
		if (byteread == -1)
			return (free(buffer), NULL);
		buffer[byteread] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free(buffer), NULL);
	}
	return (free(buffer), line);
}

char	*ft_get_line(char *line)
{
	int		len;
	char	*result;

	len = 0;
	if (!line || line[0] == '\0')
		return (NULL);
	while (line[len] != '\n' && line[len] != '\0')
		len++;
	result = ft_calloc(len + 2, sizeof(char));
	if (!result)
		return (NULL);
	len = 0;
	while (line[len] != '\n' && line[len] != '\0')
	{
		result[len] = line[len];
		len++;
	}
	if (line[len] == '\n')
	{
		result[len] = line[len];
		len++;
	}
	result[len] = '\0';
	return (result);
}

char	*line_remainder(char *line)
{
	char	*temp_line;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		temp_line = ft_calloc(1, sizeof(char));
		return (free(line), temp_line);
	}
	i++;
	temp_line = ft_calloc(ft_strlen(line) - i + 1, sizeof(char));
	if (!temp_line)
		return (NULL);
	j = 0;
	while (line[i + j])
	{
		temp_line[j] = line[i + j];
		j++;
	}
	temp_line[j] = '\0';
	return (free(line), temp_line);
}
