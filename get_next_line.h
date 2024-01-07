/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:47:14 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/07 17:08:52 by saeryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* header */
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/* macros */
# define VALID		1
# define INVALID	0
# define TRUE		1
# define FALSE		0

/* buffer */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

/* linked list */
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

/* functions */
char	*get_next_line(int fd);
void	read_and_head(int fd, t_list **head, int *readed_ptr);
void	add_to_head(t_list **head, char *buf, int readed_ptr);
void	extract_line(t_list *head, char **res);
void	clean_head(t_list **head);

/* utils */
int		found_new_line(t_list *head);
void	free_head(t_list *head);
void	generate_line(char **res, t_list *head);
t_list	*ft_lstlast(t_list *head);
size_t	ft_strlen(const char *str);

#endif