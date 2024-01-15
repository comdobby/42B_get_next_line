/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:07:59 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/15 22:57:02 by saeryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_save(int fd, char *text_data)
{
	char	*buf;
	int		res_of_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	res_of_read = 1;
	while (!ft_strchr(text_data, '\n') && res_of_read != 0)
	{
		res_of_read = read(fd, buf, BUFFER_SIZE);
		if (res_of_read == -1)
		{
			free(buf);
			free(text_data);
			return (NULL);
		}
		buf[res_of_read] = '\0';
		text_data = ft_strjoin(text_data, buf);
	}
	free(buf);
	return (text_data);
}

char	*ft_get_line(char *text_data)
{
	size_t	i;
	char	*line;

	if (!text_data || text_data[0] == '\0')
		return (NULL);
	i = 0;
	while (text_data[i] && text_data[i] != '\n')
		i++;
	i += (text_data[i] == '\n');
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (text_data[i] && text_data[i] != '\n')
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
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	while (text_data[i] && text_data[i] != '\n')
		i++;
	if (text_data[i] == '\0')
	{
		free(text_data);
		return (NULL);
	}
	i += (text_data[i] == '\n');
	rest = (char *)malloc(sizeof(char) * (ft_strlen(text_data) - i + 1));
	if (!rest)
		return (NULL);
	j = 0;
	while (text_data[i + j])
	{
		rest[j] = text_data[i + j];
		j++;
	}
	rest[j] = '\0';
	free(text_data);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*text_data;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
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
	res = get_next_line(fd);
	if (res == NULL)
	{
		printf("NULL\n");
		close(fd);
	}
	while (res)
	{
		printf("%s",res);
		free(res);
		res = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/