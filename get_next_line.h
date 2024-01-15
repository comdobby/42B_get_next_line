/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeryu <@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:07:01 by saeryu            #+#    #+#             */
/*   Updated: 2024/01/15 15:49:59 by saeryu           ###   ########.fr       */
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
#  define BUFFER_SIZE 5
# endif

/* functions */
char	*read_and_save(int fd, char *text_data);
char	*ft_get_line(char *text_data);
char	*save_rest(char *text_data);
char	*get_next_line(int fd);

/* utils */
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif