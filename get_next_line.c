/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:47:09 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/07 17:08:52 by saeryu           ###   ########.fr       */
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
	extract_line(head, &res);
	clean_head(&head);
	if (res[0] == '\0')
	{
		free_head(head);
		head = NULL;
		free(res);
		return (NULL);
	}
	return (res);
}

void	read_and_head(int fd, t_list **head, int *readed_ptr)
{
	char	*buf;

	while (!found_new_line(*head) && *readed_ptr != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
		if (buf == NULL)
			return (NULL);
		*readed_ptr = read(fd, buf, BUFFER_SIZE);
		if ((*head == NULL && readed_ptr == 0) || *readed_ptr == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[*readed_ptr] = '\0';
		add_to_head(head, buf, *readed_ptr);
		free(buf);
	}
}

void	add_to_head(t_list **head, char *buf, int readed_ptr)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed_ptr + 1));
	if (new_node->content == NULL)
		return (NULL);
	i = 0;
	while (buf[i] && i < readed_ptr)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*head == NULL)
	{
		*head = new_node;
		return (NULL);
	}
	last = ft_lstlast(*head);
	last->next = new_node;
}

void	extract_line(t_list *head, char **res)
{
	int	i;
	int	j;

	if (head == NULL)
		return (NULL);
	generate_line(*res, head);
	if (*res == NULL)
		return (NULL);
	while (head)
	{
		i = 0;
		while (head->content[i])
		{
			if (head->content[i] == '\n')
			{
				(*res)[j++] = head->content[i];
				break ;
			}
			(*res)[j++] = head->content[i++];
		}
		head = head->next;
	}
	(*res)[j] = '\0';
}

void	clean_head(t_list **head)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (head == NULL || clean_node == NULL)
		return (NULL);
	clean_node->next = NULL;
	last = ft_lstlast(*head);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] && last->content[i] == '\n')
		i++;
	clean_node->content = \
	malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
	if (clean_node->content == NULL)
		return (NULL);
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_head(*head);
	*head = clean_node;
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