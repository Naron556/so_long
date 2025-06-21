/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoperacz <aoperacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:22:33 by aoperacz          #+#    #+#             */
/*   Updated: 2025/06/21 03:19:05 by aoperacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buff)
{
	char	*temp;

	temp = ft_strjoin(buff, buffer);
	free(buff);
	return (temp);
}

char	*read_data(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*buff;
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buff = "";
	if (!buff)
		return (NULL);
	if (bytes_read == -1)
		return (free(buff), NULL);
	while (bytes_read > 0)
	{
		buff = ft_free(buffer, buff);
		if (ft_strchr(buffer, '\n'))
			break ;
		else
			bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (buff);
}

char	*find_line(char *data)
{
	int		i;
	char	*line;

	if (!data || *data == '\0')
		return (NULL);
	i = 0;
	while (data[i] != '\n' && data[i])
		i++;
	if (data[i] == '\n')
		i++;
	line = calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (data[i] != '\n' && data[i])
	{
		line[i] = data[i];
		i++;
	}
	if (data[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*find_remaining_data(char *data)
{
	ssize_t	i;
	ssize_t	j;
	char	*leftover;

	if (!data)
		return (NULL);
	i = ft_strlen(find_line(data));
	j = 0;
	while (data[i + j] || data[i + j] != '\n')
		j++;
	if (data[i + j] == '\n')
		j++;
	leftover = (char *)malloc(j * sizeof(char));
	if (!leftover)
		return (NULL);
	j = 0;
	while (data[i + j])
	{
		leftover[j] = data[i + j];
		j++;
	}
	return (leftover);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*data;
	static char	*saved_data;

	data = read_data(fd);
	if (!data)
		return (NULL);
	saved_data = ft_strjoin(saved_data, data);
	free(data);
	line = find_line(saved_data);
	saved_data = find_remaining_data(saved_data);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("/home/aoperacz/get_next_line/nice.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("Line: %s", line);
	free(line);
	close(fd);
	return (0);
}
