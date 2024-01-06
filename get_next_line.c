/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:47:09 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/06 21:39:31 by saeryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*res;
	int				readed;

	head = NULL;
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readed = 1;
	res = NULL;
	read_and_head(fd, &head, &readed);
	if (head == NULL)
		return (NULL);
	return (res);
}

void	read_and_head(int fd, t_list **head, int *readed_ptr)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (buf == NULL)
		return (NULL);
	while (!found_new_line(*head) && *readed_ptr != 0)
	{
		*readed_ptr = read(fd, buf, BUFFER_SIZE);
		if ((*head == NULL && readed_ptr == 0) || *readed_ptr == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[*readed_ptr] = '\0';
	}
}
/*
#include <stdio.h>
int	main()
{
	int		fd;
	char	*line;

	fd = open("tests/simple", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
	return (0); 
}*/