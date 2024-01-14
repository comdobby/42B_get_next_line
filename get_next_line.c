/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:47:09 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/14 20:36:56 by saeryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*temp = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	read_and_save_to_temp(fd, &temp);
	if (temp == NULL)
		return (NULL);
	get_line_from_temp(temp, &line);
	clear_temp(&temp);
	if (line[0] == '\0')
	{
		free_temp(temp);
		temp = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	read_and_save_to_temp(int fd, t_list **temp)
{
	char		*buf;
	ssize_t		res_of_read;

	res_of_read = 1;
	while (!check_newline(*temp) && res_of_read != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		res_of_read = read(fd, buf, BUFFER_SIZE);
		if ((*temp == NULL && res_of_read == 0) || res_of_read == -1)
		{
			free(buf);
			return ;
		}
		buf[res_of_read] = '\0';
		add_to_temp(temp, buf, res_of_read);
		free(buf);
	}
}

void	add_to_temp(t_list **temp, char *buf, int res_of_read)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new_node->content)
		return ;
	i = 0;
	while (buf[i] && i < res_of_read)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*temp == NULL)
	{
		*temp = new_node;
		return ;
	}
	last = ft_lstlast(*temp);
	last->next = new_node;
}

void	get_line_from_temp(t_list *temp, char **line)
{
	int	i;
	int	j;

	if (temp == NULL)
		return ;
	malloc_line(temp, line);
	if (*line == NULL)
		return ;
	j = 0;
	while (temp)
	{
		i = 0;
		while (temp->content[i])
		{
			if (temp->content[i] == '\n')
			{
				(*line)[j++] = temp->content[i];
				break ;
			}
			(*line)[j++] = temp->content[i++];
		}
		temp = temp->next;
	}
	(*line)[j] = '\0';
}

void	clear_temp(t_list **temp)
{
	int		i;
	int		j;
	t_list	*last;
	t_list	*rest;

	rest = malloc(sizeof(t_list));
	if (temp == NULL || rest == NULL)
		return ;
	rest->next = NULL;
	last = ft_lstlast(*temp);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	rest->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
	if (rest->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		rest->content[j++] = last->content[i++];
	rest->content[j] = '\0';
	free_temp(*temp);
	*temp = rest;
}
/*
# include <stdio.h>
int	main(void)
{
	const char	*path = "test.txt";
	int	fd = open(path, O_RDONLY);
	char	*line;
	
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}*/
