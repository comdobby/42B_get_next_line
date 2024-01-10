/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:47:14 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/10 17:01:13 by saeryu           ###   ########.fr       */
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
void	read_and_save_to_temp(int fd, t_list **temp);
void	add_to_temp(t_list **temp, char *buf, int res_of_read);
void	get_line_from_temp(t_list *temp, char **line);
void	clear_temp(t_list **temp);

/* utils */
t_list	*ft_lstlast(t_list *head);
int		check_newline(t_list *temp);
void	malloc_line(t_list *temp, char **line);
size_t	ft_strlen(const char *s);
void	free_temp(t_list *temp);

#endif