# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saeryu <@student.42berlin.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 16:01:33 by saeryu            #+#    #+#              #
#    Updated: 2024/01/05 16:10:19 by saeryu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

HEADER = get_next_line.h

CC = cc

CCFLAG = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CCFLAG) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re