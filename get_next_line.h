/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:47:14 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/06 21:29:21 by saeryu           ###   ########.fr       */
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
t_list	*ft_lstlast(t_list *head);
size_t	ft_strlen(const char *str);

#endif