# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/05 18:28:50 by nclabaux          #+#    #+#              #
#    Updated: 2020/06/10 14:50:38 by nclabaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRCS =	calculus.c\
	colors.c\
	distances.c\
	errors.c\
	file_reading.c\
	file_reading1.c\
	file_reading2.c\
	images.c\
	light.c\
	intersection.c\
	intersection1.c\
	list_handling.c\
	main.c\
	vectorial_calculus.c\
	vectorial_calculus1.c\
	verification.c\
	verification1.c

A = loop.c

OBJS = $(SRCS:.c=.o)

CC = gcc 

RM = rm -f

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
LIBFLAGS = -lm -lmlx -lXext -lX11 -L./libft -lft

$(NAME): $(OBJS)
	make -C libft/ 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFLAGS)

all: $(NAME)

clean: 
	make -C libft/ clean
	$(RM) $(OBJS)

fclean: clean
	make -C libft/ fclean
	$(RM) $(NAME)

re: fclean all

mactest:
	gcc tester.c -lmlx -framework OpenGL -framework AppKit 

linuxtest:
	make -C libft/ 
	clang tester.c f_main.c $(SRCS) $(LIBFLAGS) 

.PHONY: all clean fclean re

#.SILENT: all clean fclean re $(NAME) $(OBJS) make
