/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:47:05 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/07 17:08:53 by saeryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_new_line(t_list *head)
{
	int		i;
	t_list	*current;

	if (head == NULL)
		return (0);
	current = ft_lstlast(head);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	free_head(t_list *head)
{
	t_list	*current;
	t_list	*next;

	current = head;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

t_list	*ft_lstlast(t_list *head)
{
	t_list	*node;

	node = head;
	while (node && node->next)
		node = node->next;
	return (node);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	generate_line(char **res, t_list *head)
{
	int	i;
	int	len;

	len = 0;
	while (head)
	{
		i = 0;
		while (head->content[i])
		{
			if (head->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		head = head->next;
		*res = malloc(sizeof(char) * (len + 1));
		if (res == NULL)
			return (NULL);
	}
}
