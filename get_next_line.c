/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:07:59 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/15 17:12:13 by saeryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_save(int fd, char *text_data)
{
	int		size;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	size = 1;
	while (!ft_strchr(text_data, '\n') && size >= 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
		{
			free(buf);
			free(text_data);
			return (NULL);
		}
		buf[size] = '\0';
		text_data = ft_strjoin(text_data, buf);
	}
	free(buf);
	return (text_data);
}

char	*ft_get_line(char *text_data)
{
	int		i;
	char	*line;

	if (!text_data || (text_data[0] == '\0'))
		return (NULL);
	i = 0;
	while (text_data[i] != '\n' && text_data[i])
		i++;
	i += (text_data[i] == '\n');
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (text_data[i] != '\n' && text_data[i])
	{
		line[i] = text_data[i];
		i++;
	}
	if (text_data[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*save_rest(char *text_data)
{
	int		len;
	int		i;
	char	*rest;

	len = 0;
	while (text_data[len] != '\n' && text_data[len])
		len++;
	if (!text_data[len])
	{
		free(text_data);
		return (NULL);
	}
	len += (text_data[len] == '\n');
	rest = (char *)malloc(sizeof(char) * (ft_strlen(text_data) - len + 1));
	if (!rest)
		return (NULL);
	i = 0;
	while (text_data[len + i])
	{
		rest[i] = text_data[len + i];
		i++;
	}
	rest[i] = '\0';
	free(text_data);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*text_data = NULL;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	text_data = read_and_save(fd, text_data);
	if (!text_data)
		return (NULL);
	line = ft_get_line(text_data);
	text_data = save_rest(text_data);
	return (line);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*path = "test.txt";
	char	*res;
	int		fd;


	fd = open(path, O_RDONLY);
	if (fd == 0 || fd < 0)
		printf("error: fail to open file\n");
	res = get_next_line(fd);
	if (res == NULL)
		printf("error: can't not read.\n");
	while (res)
	{
		printf("%s",res);
		free(res);
		res = get_next_line(fd);
	}
	close(fd);
	return (0);
}
*/