/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:47:05 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/10 17:01:17 by saeryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *head)
{
	t_list	*node;

	node = head;
	while (node && node->next)
		node = node->next;
	return (node);
}

int	check_newline(t_list *temp)
{
	int		i;
	t_list	*current;

	if (temp == NULL)
		return (0);
	current = ft_lstlast(temp);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	malloc_line(t_list *temp, char **line)
{
	int	i;
	int	len;

	len = 0;
	while (temp)
	{
		i = 0;
		while (temp->content[i])
		{
			if (temp->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		temp = temp->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	free_temp(t_list *temp)
{
	t_list	*current;
	t_list	*next;

	current = temp;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
