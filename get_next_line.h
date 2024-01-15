/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:07:01 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/15 23:00:51 by saeryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* header */
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/* buffer */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* functions */
char	*read_and_save(int fd, char *text_data);
char	*ft_get_line(char *text_data);
char	*save_rest(char *text_data);
char	*get_next_line(int fd);

/* utils */
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);

#endif