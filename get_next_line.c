/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gualvare <gualvare@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:02:46 by gualvare          #+#    #+#             */
/*   Updated: 2024/07/28 15:42:57 by gualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*protect_join(char	*buffer, char *reading)
{
	char	*tmp;

	tmp = strjoin(buffer, reading);
	if (!tmp)
		return (ft_free(&buffer));
	return (tmp);
}

char	*update_buffer(char *buffer, char *line)
{
	char	*updated_buffer;
	int		len;
	int		start;
	int		i;

	i = 0;
	start = strchrpos(buffer, '\n', FALSE);
	len = strchrpos(buffer, 0, FALSE) - strchrpos(line, 0, FALSE);
	if (!buffer[start])
		return (ft_free(&buffer));
	updated_buffer = ft_calloc(len + 1, sizeof(char));
	if (updated_buffer == NULL)
		return (ft_free(&buffer));
	while (buffer[++start])
		updated_buffer[i++] = buffer[start];
	free(buffer);
	return (updated_buffer);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	len = strchrpos(buffer, '\n', FALSE);
	if (len == NOT_FOUND)
		len = strchrpos(buffer, '\0', FALSE);
	len++;
	line = ft_calloc(len + 1, sizeof(char));
	if (line == NULL)
		return (NULL);
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char	*read_line(int fd, char *buffer)
{
	char		*tmp;
	int			read_bytes;

	read_bytes = 1;
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (ft_free(&buffer), ft_free(&tmp));
	while (read_bytes > 0)
	{
		if (strchrpos(tmp, '\n', TRUE) != NOT_FOUND)
			break ;
		read_bytes = read(fd, tmp, BUFFER_SIZE);
		if (read_bytes < 0)
			return (ft_free(&buffer), ft_free(&tmp));
		tmp[read_bytes] = '\0';
		buffer = protect_join(buffer, tmp);
		if (!buffer)
			return (NULL);
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer)
			return (ft_free(&buffer));
		return (NULL);
	}
	if (!buffer)
		buffer = ft_calloc(1, 1);
	if (!buffer)
		return (ft_free(&buffer));
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	if (!line || *line == '\0')
		return (ft_free(&buffer), ft_free(&line));
	buffer = update_buffer(buffer, line);
	return (line);
}
