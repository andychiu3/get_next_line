/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:19:33 by achiu             #+#    #+#             */
/*   Updated: 2025/02/11 13:53:47 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_text(int fd, char *buffer)
{
	int		byte_read;
	char	*buf;
	char	*temp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	byte_read = 1;
	if (!buffer)
		buffer = ft_strdup("");
	while (byte_read)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
			return (0);
		buf[byte_read] = 0;
		temp = buffer;
		buffer = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (buffer);
}

static char	*get_line(char *line)
{
	int		len;
	char	*tmp;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (line[len] == '\n')
		len++;
	tmp = line;
	line = ft_substr(tmp, 0, len);
	free(tmp);
	return (line);
}

static char	*nextline(char *line)
{
	int		start;
	char	*buf;
	int		end;

	start = 0;
	while (line[start] && line[start] != '\n')
		start++;
	if (line[start] == '\n')
		start++;
	if (line[start] == 0)
		return (0);
	end = ft_strlen(line);
	buf = ft_substr(line, start, end - start);
	if (!buf)
	{
		free(buf);
		return (0);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (read(fd, 0, 0) < 0)
	{
		free (buffer);
		buffer = NULL;
		return (0);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (buffer);
		return (0);
	}
	line = read_text(fd, buffer);
	buffer = nextline(line);
	line = get_line(line);
	return (line);
}

// int	main(int ac, char **av)
// {
// 	int		fd;
// 	char	*line;

// 	if (ac > 1)
// 	{
// 		fd = open(av[1], O_RDONLY);
// 		if (fd == -1)
// 			return (perror("open"), 1);
// 		line = get_next_line(fd);
// 		while (line)
// 		{
// 			printf("%s\n", line);
// 			free(line);
// 			line = get_next_line(fd);
// 		}
// 		close(fd);
// 	}
// 	return (0);
// }
